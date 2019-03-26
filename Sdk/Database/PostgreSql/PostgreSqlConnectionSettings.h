#ifndef POSTGRESQLCONNECTIONSETTINGS_H
#define POSTGRESQLCONNECTIONSETTINGS_H

#include <string>
#include <inttypes.h>

#include <Sdk/property.h>
#include <Sdk/Database/IDatabaseConnectionSettings.h>

namespace energy { namespace database {

class SDKSHARED_EXPORT PostgreSqlConnectionSettings :
        public IDatabaseConnectionSettings
{
public:
    PostgreSqlConnectionSettings();
    virtual ~PostgreSqlConnectionSettings() override = default;

    // IStringable interface
public:
    virtual std::string toString() const override;
    virtual void toString(std::string &buffer) const override;

    PR(uint16_t, Port)
    PR(const char *, Database)
    PR(const char *, Host)
    PR(const char *, Username)
    PR(const char *, Password)

};

} }

#endif // POSTGRESQLCONNECTIONSETTINGS_H
