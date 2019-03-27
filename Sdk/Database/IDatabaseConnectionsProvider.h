#ifndef IDATABASECONNECTIONSPROVIDER_H
#define IDATABASECONNECTIONSPROVIDER_H

#include <vector>

#include <Sdk/export.h>
#include <Sdk/Database/IDatabaseConnection.h>

namespace energy { namespace database {

/**
 * @brief Класс для обработки коллекции подключений к базе данных.
 * Должен выполнять функции контроля "подвисших" подключений, распараллеливать запросы между подключениями.
 */
class SDKSHARED_EXPORT IDatabaseConnectionsProvider
{
public:
    IDatabaseConnectionsProvider();
    virtual ~IDatabaseConnectionsProvider();

    /**
     * @brief Добавляет новое подключение к базе данных на контроль к провайдеру.
     * @param connection подключение к базе данных
     * @throw std::bad_alloc Не удалось выделить память, для добавления элемента в коллекцию
     */
    void registerConnection(IDatabaseConnection *connection);

private:
    /**
     * @brief DatabaseConnectionContext вспомогательный класс, необходимый для контроля работы подключений.
     */
    class DatabaseConnectionContext
    {
    public:
        /**
         * @brief Connection Подключение к базе данных
         */
        IDatabaseConnection *Connection;
        /**
         * @brief Terminated было ли подключение умышленно разорвано
         */
        bool Terminated;
    };
    std::vector<DatabaseConnectionContext *> _connectionVector;
};

} }

#endif // IDATABASECONNECTIONSPROVIDER_H
