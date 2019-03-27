#ifndef IDATABASEQUERY_H
#define IDATABASEQUERY_H

#include <cinttypes>
#include <memory>

#include <Sdk/singleton.h>
#include <Sdk/Database/IDatabaseValue.h>

namespace energy { namespace database {

/**
 * @brief Результат выполнения запроса к базе данных
 */
class IDatabaseQuery
{
    INTERFACE(IDatabaseQuery);

public:

    /**
     * @brief Возвращает количество строк
     */
    virtual size_t getNumRows() const = 0;
    /**
     * @brief Возвращает количество столбцов
     */
    virtual size_t getNumColumns() const = 0;

    /**
     * @brief Возвращает наименование колонки по ее номеру
     * @throw std::out_of_range номер колонки больше, чем их количество
     */
    virtual const char *getColumn(size_t index) const = 0;
    /**
     * @brief Возвращает номер колонки по ее названию
     * @throw std::out_of_range колонка с указанным наименованием не найдена
     */
    virtual size_t getColumnIndex(const char *name) const = 0;
    /**
     * @brief Проверяет пустоту результата
     * @return true, если в результате нет строк
     */
    virtual bool isEmpty() const = 0;
    /**
     * @brief Переводит указатель на новую строку
     */
    virtual bool next() = 0;
    /**
     * @brief Получить значение колонки в текущей строке
     * @param column Номер колонки
     * @return Значение поля
     */
    virtual std::shared_ptr<IDatabaseValue> getValue(size_t column) const = 0;
};

} }

#endif // IDATABASEQUERY_H
