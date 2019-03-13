#include "PostgreSqlConnection.h"

using namespace energy::database;

PostgreSqlConnection::PostgreSqlConnection() :
    IDatabaseConnection()
{

}

PostgreSqlConnection::~PostgreSqlConnection()
{

}

void PostgreSqlConnection::open()
{

}

void PostgreSqlConnection::close() noexcept
{

}

bool PostgreSqlConnection::isOpen() const noexcept
{
    return false;
}
