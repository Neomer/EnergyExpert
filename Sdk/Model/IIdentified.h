#ifndef IIDENTIFIED_H
#define IIDENTIFIED_H

namespace energy { namespace model {

/**
 * IIdentified<T> интерфейс для всех классов, имеющих идентификатор.
 * Тип T - базовый тип или класс, который переопределил оператор сравнения для корректной работы метода IIdentified::isEquals(const IIdentified<T> &other).
 */
template <typename T>
class IIdentified
{
public:
    /**
     * @brief IIdentified Инициализирует класс с конструктором типа идентификатора по-умолчанию
     */
    IIdentified() : _id{} { }
    /**
     * @brief IIdentified Инициализирует класс с конструктором копирования типа идентификатора. Значение идентификатора передается по константной ссылке.
     * @param id
     */
    IIdentified(const T &id) : _id { id }  { }

    /**
     * @brief getId_const возвращает идентификатор объекта.
     * @return Константная ссылка на идентификатор.
     */
    const T &getId_const() const { return _id; }
    /**
     * @brief getId возвращает идентификатор объекта.
     * @return Ссылка на идентификатор.
     */
    T &getId() const { return _id; }
    /**
     * @brief setId устанавливает идентификатор
     * @param id константная ссылка на идентификатор
     */
    void setId(const T &id) { _id = id; }
    /**
     * @brief setId устанавливает идентификатор
     * @param id значение идентификатора
     */
    void setId(T id) { _id = id; }
    /**
     * @brief isEquals сравнивает два объекта
     * @param other объект для сравнения
     * @return True, если два  объекта имеют одинаковый идентификатор
     */
    bool isEquals(const IIdentified<T> &other) const { return _id == other._id; }

private:
    T _id;
};

} }

#endif // IIDENTIFIED_H
