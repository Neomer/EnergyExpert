#ifndef IDATABASECONNECTION_H
#define IDATABASECONNECTION_H

#include <memory>

#include <Sdk/export.h>
#include <Sdk/Database/IDatabaseConnectionSettings.h>
#include <Sdk/Database/IDatabaseTransaction.h>

namespace energy { namespace database {

/**
 * @brief IDatabaseConnection абстрактный класс для активного подключения к базе данных.
 * Используется для создания подключения к базе данных. Все активные подключения обслуживаются IDatabaseConnectionsProvider.
 */
class SDKSHARED_EXPORT IDatabaseConnection
{
public:
    IDatabaseConnection() = default;
    virtual ~IDatabaseConnection() = default;

    /**
     * @brief open открывает подключение к базе данных.
     * @throw energy::exceptions::DatabaseNotOpenException Не удалось открыть подключение
     * @throw energy::exceptions::NullPointerException Не заданы настройки для подключения к серверу
     */
    virtual void open() = 0;
    /**
     * @brief close закрывает подключение к базе данных
     */
    virtual void close() noexcept = 0;
    /**
     * @brief isOpen используется для проверки открыто ли подключение
     * @return True, если подключение открыто и готово для использования.
     */
    virtual bool isOpen() const noexcept = 0;
    /**
     * @brief Устанавливает параметры подключения к базе данных
     */
    virtual void setConnectionSettings(const IDatabaseConnectionSettings *settings) = 0;
    /**
     * @brief Возвращает текущие параметры подключения к базе данных
     */
    virtual const IDatabaseConnectionSettings *getConnectionSettings() const = 0;
    /**
     * @brief Создает новую транзакцию, внутри подключения.
     */
    virtual std::shared_ptr<IDatabaseTransaction> createTransaction() const = 0;
};

} }
#endif // IDATABASECONNECTION_H
