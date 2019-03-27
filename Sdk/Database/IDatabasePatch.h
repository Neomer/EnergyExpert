#ifndef IDATABASEPATCH_H
#define IDATABASEPATCH_H

#include <Sdk/singleton.h>

namespace energy::database {

class IDatabaseTransaction;

/**
 * @brief Интерфейс для реализации патчей для базы данных.
 * Патч для базы данных - атомарное изменение состояния базы данных, которое служит для применения изменений.
 * Патчи индивидуальны для каждой базы данных и следуют в строгом порядке.
 */
class IDatabasePatch
{
    INTERFACE(IDatabasePatch);

public:
    /**
     * @brief Применить патч
     * @param connection Подключение к базе данных
     * @throw energy::exceptions::DatabaseExecutionFailed Не удалось применить патч
     */
    virtual void execute(IDatabaseTransaction *transaction) = 0;
};

}

#endif // IDATABASEPATCH_H
