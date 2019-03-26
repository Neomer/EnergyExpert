#ifdef POSTGRESQL_SUPPORT

#include <libpq-fe.h>

#include <Sdk/Database/Exceptions/DatabaseExecutionFailed.h>
#include <Sdk/Database/Exceptions/DatabaseCommitFailedException.h>
#include <Sdk/Database/PostgreSql/PostgreSqlQuery.h>
#include <Sdk/Core/Exceptions/NullPointerException.h>

#include "PostgreSqlTransaction.h"

using namespace energy::exceptions;
using namespace energy::database;

PostgreSqlTransaction::PostgreSqlTransaction(void *connection) :
    _connection{ connection }
{
    if (_connection == nullptr) {
        throw NullPointerException();
    }
}

PostgreSqlTransaction::~PostgreSqlTransaction()
{

}

std::shared_ptr<IDatabaseQuery> PostgreSqlTransaction::exec(const char *query) const
{
    auto result = PQexec(static_cast<PGconn *>(_connection), query);
    auto status = PQresultStatus(static_cast<PGresult *>(result));
    if (status != PGRES_COMMAND_OK && status != PGRES_TUPLES_OK && status != PGRES_SINGLE_TUPLE) {
        throw DatabaseExecutionFailed();
    }
    return std::shared_ptr<IDatabaseQuery>(new PostgreSqlQuery(result));
}

void PostgreSqlTransaction::commit()
{
    PGresult *result = PQexec(static_cast<PGconn *>(_connection), "commit");
    auto status = PQresultStatus(result);
    if (status != PGRES_COMMAND_OK && status != PGRES_TUPLES_OK && status != PGRES_SINGLE_TUPLE) {
        throw DatabaseCommitFailedException();
    }
}

void PostgreSqlTransaction::rollback()
{
    PQexec(static_cast<PGconn *>(_connection), "rollback");
}

#endif
