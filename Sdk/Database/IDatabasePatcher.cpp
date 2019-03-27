#include <string>

#include "IDatabasePatcher.h"
#include <Sdk/Database/Exceptions/DatabaseNotOpenException.h>
#include <Sdk/Database/Exceptions/DatabaseExecutionFailed.h>
#include <Sdk/Database/Exceptions/DatabaseCommitFailedException.h>

using namespace energy::exceptions;
using namespace energy::database;

IDatabasePatcher::IDatabasePatcher(const IDatabaseConnectionSettings *connectionSettings) :
    _connectionSettings{ connectionSettings }
{

}

void IDatabasePatcher::applyPatches()
{
    std::vector<std::shared_ptr<IDatabasePatch>> patchList;
    fillPatchList(patchList);

    auto maxVersion = patchList.size();

    auto connection = createConnection(_connectionSettings);
    try {
        connection->open();

        auto tr = connection->createTransaction();
        try {
            auto q = tr->exec("select * from DB_Version;");
            tr->commit();
            auto version = q->getValue(q->getColumnIndex("Version"))->asUInt32();
            if (version < maxVersion) {
                for (auto it = patchList.begin() + version - 1; it != patchList.end(); ++it, ++version) {
                    tr = connection->createTransaction();
                    try {
                        (*it)->execute(tr.get());
                        tr->exec(std::string("update DB_Version set Version=").append(std::to_string(version)).c_str());
                        tr->commit();
                    } catch (DatabaseCommitFailedException &) {
                        //WARNING: обработка исключения на невозможность применения патча
                        return;
                    }
                }
            }
        } catch (DatabaseExecutionFailed &) {
            //WARNING: Обработка исключения при попытке получить версию базы данных
        }

        connection->close();
    } catch (DatabaseNotOpenException &) {
        //WARNING: Обработка исключения при невозможности подключения к базе!
    }
}
