#ifdef POSTGRESQL_SUPPORT

#include <Sdk/Database/PostgreSql/PostgreSqlConnection.h>
#include "PostgreSqlPatcher.h"

#include <Sdk/Database/PostgreSql/Patches/DatabaseCreationPatch.h>

using namespace energy::database;

PostgreSqlPatcher::PostgreSqlPatcher(const IDatabaseConnectionSettings *settings) :
    IDatabasePatcher{ settings }
{

}

void PostgreSqlPatcher::fillPatchList(std::vector<std::shared_ptr<IDatabasePatch> > &patches)
{
    patches.push_back(std::shared_ptr<IDatabasePatch>(new DatabaseCreationPatch()));
}

IDatabaseConnection *PostgreSqlPatcher::createConnection(const IDatabaseConnectionSettings *settings)
{
    auto connection = new PostgreSqlConnection();
    connection->setConnectionSettings(settings);
    return connection;
}

#endif
