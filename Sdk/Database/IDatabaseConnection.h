#ifndef IDATABASECONNECTION_H
#define IDATABASECONNECTION_H

namespace energy { namespace database {

/**
 * @brief IDatabaseConnection абстрактный класс для активного подключения к базе данных.
 * Используется для создания подключения к базе данных. Все активные подключения обслуживаются IDatabaseConnectionsProvider.
 */
class IDatabaseConnection
{
public:
    IDatabaseConnection() = default;
    virtual ~IDatabaseConnection() = default;

    /**
     * @brief open открывает подключение к базе данных.
     * @throw energy::exceptions::DatabaseNotOpenException Не удалось открыть подключение
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
};

} }
#endif // IDATABASECONNECTION_H
