#ifndef IIDENTIFIED_H
#define IIDENTIFIED_H

#include <Sdk/export.h>

namespace energy { namespace model {

/**
 * IIdentified<T> интерфейс для всех классов, имеющих идентификатор.
 * Тип T - базовый тип или класс, который переопределил оператор сравнения для корректной работы метода IIdentified::isEquals(const IIdentified<T> &other).
 */
template <typename T>
class SDKSHARED_EXPORT IIdentified
{
public:
    /**
     * @brief Инициализирует класс с конструктором типа идентификатора по-умолчанию
     */
    IIdentified() : _id{} { }
    /**
     * @brief Инициализирует класс с конструктором копирования типа идентификатора. Значение идентификатора передается по константной ссылке.
     * @param id
     */
    IIdentified(const T &id) : _id { id }  { }

    /**
     * @brief Возвращает идентификатор объекта.
     * @return Константная ссылка на идентификатор.
     */
    const T &getId_const() const { return _id; }
    /**
     * @brief Возвращает идентификатор объекта.
     * @return Ссылка на идентификатор.
     */
    T &getId() { return _id; }
    /**
     * @brief Устанавливает идентификатор по константной ссылке
     * @param id константная ссылка на идентификатор
     */
    void setId(const T &id) { _id = id; }
    /**
     * @brief Устанавливает идентификатор по значению через конструктор копирования.
     * Рекомендуется использовать только для простых типов.
     * @param id значение идентификатора
     */
    void setIdByValue(T id) { _id = id; }
    /**
     * @brief Сравнивает два объекта
     * @param other объект для сравнения
     * @return True, если два  объекта имеют одинаковый идентификатор
     */
    bool isEquals(const IIdentified<T> &other) const { return _id == other._id; }

private:
    T _id;
};

} }

#endif // IIDENTIFIED_H
