#ifndef IDATABASECONNECTIONSETTINGS_H
#define IDATABASECONNECTIONSETTINGS_H

#include <Sdk/Core/Types/ICloneable.h>
#include <Sdk/Core/Types/IStringable.h>

namespace energy { namespace database {

/**
 * @brief Общий интерфейс для настроек подключения к базе данных.
 */
class IDatabaseConnectionSettings :
        public energy::core::types::IStringable
{
public:
    IDatabaseConnectionSettings() = default;
    virtual ~IDatabaseConnectionSettings() = default;
};

} }

#endif // IDATABASECONNECTIONSETTINGS_H
