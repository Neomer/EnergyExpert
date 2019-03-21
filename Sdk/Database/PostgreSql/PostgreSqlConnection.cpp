#ifdef POSTGRESQL_SUPPORT

#include <libpq-fe.h>

#include <Sdk/Database/PostgreSql/PostgreSqlTransaction.h>
#include <Sdk/Database/Exceptions/DatabaseNotOpenException.h>
#include <Sdk/Database/PostgreSql/PostgreSqlConnectionSettings.h>
#include <Sdk/Core/Exceptions/NullPointerException.h>

#include "PostgreSqlConnection.h"

using namespace energy::database;
using namespace energy::exceptions;

PostgreSqlConnection::PostgreSqlConnection() :
    IDatabaseConnection(),
    _settings{ nullptr }
{

}

PostgreSqlConnection::~PostgreSqlConnection()
{
    close();
}

void PostgreSqlConnection::open()
{
    if (_settings == nullptr) {
        throw NullPointerException("Настройки подключения не инициализированы!");
    }
    auto postgreSqlSettings = static_cast<const PostgreSqlConnectionSettings *>(_settings);

    _conn = PQsetdbLogin(
                postgreSqlSettings->getHost(),
                std::to_string(postgreSqlSettings->getPort()).c_str(),
                nullptr, nullptr,
                postgreSqlSettings->getDatabase(),
                postgreSqlSettings->getUsername(),
                postgreSqlSettings->getPassword());
    if (!isOpen()) {
        throw DatabaseNotOpenException();
    }
}

void PostgreSqlConnection::close() noexcept
{
    if (_conn != nullptr) {
        PQfinish(static_cast<PGconn *>(_conn));
        _conn = nullptr;
    }
}

bool PostgreSqlConnection::isOpen() const noexcept
{
    if (_conn == nullptr) {
         return false;
    }
    auto status = PQstatus(static_cast<PGconn *>(_conn));
    return status == CONNECTION_OK;
}

void PostgreSqlConnection::setConnectionSettings(const IDatabaseConnectionSettings *settings)
{
    _settings = settings;
}

const IDatabaseConnectionSettings *PostgreSqlConnection::getConnectionSettings() const
{
    return _settings;
}

std::shared_ptr<IDatabaseTransaction> energy::database::PostgreSqlConnection::createTransaction() const
{
    PQexec(static_cast<PGconn *>(_conn), "BEGIN");
    return std::shared_ptr<IDatabaseTransaction>(new PostgreSqlTransaction(_conn));
}

#endif
