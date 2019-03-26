#ifndef POSTGRESQLTRANSACTION_H
#define POSTGRESQLTRANSACTION_H

#include <Sdk/export.h>
#include <Sdk/Database/IDatabaseTransaction.h>

namespace energy { namespace database {

class SDKSHARED_EXPORT PostgreSqlTransaction : public IDatabaseTransaction
{
public:
    using FakePgConnType = void*;

    PostgreSqlTransaction(FakePgConnType connection);
    virtual ~PostgreSqlTransaction() override;

private:
    FakePgConnType _connection;

    // IDatabaseTransaction interface
public:
    virtual std::shared_ptr<IDatabaseQuery> exec(const char *query) const override;
    virtual void commit() override;
    virtual void rollback() override;
};

} }

#endif // POSTGRESQLTRANSACTION_H
