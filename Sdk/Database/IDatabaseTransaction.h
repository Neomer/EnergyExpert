#ifndef IDATABASETRANSACTION_H
#define IDATABASETRANSACTION_H

#include <memory>

#include <Sdk/Database/IDatabaseQuery.h>

namespace energy { namespace database {

/**
 * @brief Транзакция базы данных.
 * Любой запрос должен быть частью транзакции.
 */
class IDatabaseTransaction
{
public:
    enum TransactionState {
        Active,
        Commited,
        Rolled
    };

    IDatabaseTransaction();
    virtual ~IDatabaseTransaction() = default;

    /**
     * @brief Выполнить запрос внутри текущей транзакции
     * @param query SQL-запрос.
     * energy::exceptions::DatabaseExecutionFailed Ошибка при выполнении запроса
     */
    virtual std::shared_ptr<IDatabaseQuery> exec(const char *query) const = 0;
    /**
     * @brief Применить изменения, внесенные это транзакцией
     * @throw energy::exceptions::DatabaseCommitFailedException Применение изменений транзакции не удалось
     */
    virtual void commit() = 0;
    /**
     * @brief Откатить изменения
     */
    virtual void rollback() = 0;

    virtual TransactionState getState() const;

protected:
    TransactionState _transactionState;
};

} }

#endif // IDATABASETRANSACTION_H
