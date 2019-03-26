#ifdef POSTGRESQL_SUPPORT

#include <libpq-fe.h>
#include <Sdk/Core/Exceptions/NullPointerException.h>
#include <Sdk/Database/Exceptions/DatabaseExecutionFailed.h>
#include <Sdk/Database/PostgreSql/PostgreSqlValue.h>

#include "PostgreSqlQuery.h"

using namespace energy::exceptions;
using namespace energy::database;

PostgreSqlQuery::PostgreSqlQuery(FakePgResultType result) :
    _result{ result },
    _idx{ 0 }
{
    if (_result == nullptr) {
        throw NullPointerException();
    }
}

PostgreSqlQuery::~PostgreSqlQuery()
{

}

bool PostgreSqlQuery::isEmpty() const
{
    return getNumRows() == 0;
}

bool PostgreSqlQuery::next()
{
    if (_idx >= getNumRows()) {
        return false;
    }
    ++_idx;
    return true;
}

size_t PostgreSqlQuery::getNumRows() const
{
    return static_cast<size_t>(PQntuples(static_cast<PGresult *>(_result)));
}

size_t PostgreSqlQuery::getNumColumns() const
{
    return static_cast<size_t>(PQnfields(static_cast<PGresult *>(_result)));
}

std::shared_ptr<IDatabaseValue> PostgreSqlQuery::getValue(size_t column) const
{
    auto sdata = PQgetvalue(static_cast<PGresult *>(_result), static_cast<int>(_idx), static_cast<int>(column));

    return std::shared_ptr<IDatabaseValue>(new PostgreSqlValue(sdata));
}

const char *PostgreSqlQuery::getColumn(size_t index) const
{
    return PQfname(static_cast<PGresult *>(_result), static_cast<int>(index));
}

size_t PostgreSqlQuery::getColumnIndex(const char *name) const
{
    return static_cast<size_t>(PQfnumber(static_cast<PGresult *>(_result), name));
}

#endif
