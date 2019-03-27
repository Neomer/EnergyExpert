#ifdef POSTGRESQL_SUPPORT

#include <sstream>

#include "PostgreSqlConnectionSettings.h"

using namespace energy::database;

PostgreSqlConnectionSettings::PostgreSqlConnectionSettings() :
    _Port{ 5432 },
    _Host{ "localhost" }
{

}

std::string PostgreSqlConnectionSettings::toString() const
{
    std::stringstream stream;
    stream << "" << _Username << ":" << _Password << "@" << _Host << ":" << std::to_string(_Port) << "/" << _Database;
    return stream.str();
}

void PostgreSqlConnectionSettings::toString(std::string &buffer) const
{
    std::stringstream stream;
    stream << "" << _Username << ":" << _Password << "@" << _Host << ":" << std::to_string(_Port) << "/" << _Database;
    buffer = stream.str();
}

#endif
