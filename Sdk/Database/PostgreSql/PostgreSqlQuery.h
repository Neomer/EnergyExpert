#ifndef POSTGRESQLQUERY_H
#define POSTGRESQLQUERY_H

#include <cinttypes>
#include <Sdk/Database/IDatabaseQuery.h>

namespace energy::database {

class SDKSHARED_EXPORT PostgreSqlQuery : public IDatabaseQuery
{
public:
    using FakePgResultType = void*;

    PostgreSqlQuery(FakePgResultType result);
    virtual ~PostgreSqlQuery() override;

    // IDatabaseQuery interface
public:
    virtual bool isEmpty() const override;
    virtual bool next() override;
    virtual size_t getNumRows() const override;
    virtual size_t getNumColumns() const override;
    virtual const char *getColumn(size_t index) const override;
    virtual size_t getColumnIndex(const char *name) const override;
    virtual std::shared_ptr<IDatabaseValue> getValue(size_t column) const override;

private:
    FakePgResultType _result;
    size_t _idx;
};

}

#endif // POSTGRESQLQUERY_H
