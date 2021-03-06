#ifndef IDATABASECONNECTIONSETTINGS_H
#define IDATABASECONNECTIONSETTINGS_H

#include <Sdk/singleton.h>
#include <Sdk/Core/Types/ICloneable.h>
#include <Sdk/Core/Types/IStringable.h>

namespace energy { namespace database {

/**
 * @brief Общий интерфейс для настроек подключения к базе данных.
 */
class IDatabaseConnectionSettings :
        public energy::core::types::IStringable
{
    INTERFACE(IDatabaseConnectionSettings)
};

} }

#endif // IDATABASECONNECTIONSETTINGS_H
