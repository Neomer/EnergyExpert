#ifndef POSTGRESQLCONNECTION_H
#define POSTGRESQLCONNECTION_H

#include <export.h>
#include <Database/IDatabaseConnection.h>

namespace energy { namespace database {

class SDKSHARED_EXPORT PostgreSqlConnection : public IDatabaseConnection
{
public:
    PostgreSqlConnection();
    ~PostgreSqlConnection();

    // IDatabaseConnection interface
public:
    virtual void open() override;
    virtual void close() noexcept override;
    virtual bool isOpen() const noexcept override;
};

} }


#endif // POSTGRESQLCONNECTION_H
