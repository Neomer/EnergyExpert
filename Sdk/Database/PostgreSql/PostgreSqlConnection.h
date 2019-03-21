#ifndef POSTGRESQLCONNECTION_H
#define POSTGRESQLCONNECTION_H

#include <Sdk/export.h>
#include <Sdk/Database/IDatabaseConnection.h>

namespace energy { namespace database {

class SDKSHARED_EXPORT PostgreSqlConnection : public IDatabaseConnection
{
public:
    using FakePgConnType = void*;

    PostgreSqlConnection();
    virtual ~PostgreSqlConnection() override;

    // IDatabaseConnection interface
public:
    virtual void open() override;
    virtual void close() noexcept override;
    virtual bool isOpen() const noexcept override;
    virtual void setConnectionSettings(const IDatabaseConnectionSettings *settings) override;
    virtual const IDatabaseConnectionSettings *getConnectionSettings() const override;
    virtual std::shared_ptr<IDatabaseTransaction> createTransaction() const override;

private:
    FakePgConnType _conn;
    const IDatabaseConnectionSettings *_settings;
};

} }


#endif // POSTGRESQLCONNECTION_H
