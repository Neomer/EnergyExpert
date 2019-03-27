#ifndef IDATABASEPATCHER_H
#define IDATABASEPATCHER_H

#include <vector>
#include <memory>

#include <Sdk/Database/IDatabaseConnectionSettings.h>
#include <Sdk/Database/IDatabaseConnection.h>
#include <Sdk/Database/IDatabasePatch.h>

namespace energy::database {

/**
 * @brief Абстрактный класс для классов-патчеров базы данных.
 */
class IDatabasePatcher
{
public:
    IDatabasePatcher(const IDatabaseConnectionSettings *connectionSettings);
    virtual ~IDatabasePatcher() = default;

    /**
     * @brief Применить патчи
     */
    void applyPatches();

protected:
    /**
     * @brief Заполняет переданный вектор списком патчей для текущей базы данных
     * @param patches Пустой вектор, который необходимо заполнить
     */
    virtual void fillPatchList(std::vector<std::shared_ptr<IDatabasePatch>> &patches) = 0;
    /**
     * @brief Создать активное подключение для текущих настроек соединения
     * @param settings Настройки подключения к базе данных
     */
    virtual IDatabaseConnection *createConnection(const IDatabaseConnectionSettings *settings) = 0;

private:
    const IDatabaseConnectionSettings *_connectionSettings;
};

}

#endif // IDATABASEPATCHER_H
