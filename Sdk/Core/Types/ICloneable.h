#ifndef ICLONEABLE_H
#define ICLONEABLE_H

#include <Sdk/export.h>
#include <Sdk/singleton.h>

namespace energy { namespace core { namespace types {

/**
 * @brief ICloneable<T> интерфейс, реализации которого должны предоставлять копии самого себя.
 * T - тип, в который может быть клонирован исходный тип. Для типа T должен быть доступен конструктор копирования.
 */
template<typename T>
class ICloneable
{
    INTERFACE(ICloneable);

public:
    /**
     * @brief clone создает копию объекта
     * @return копия объекта
     */
    virtual T clone() const = 0;
    /**
     * @brief copyTo копирует состояние объекта в другой объект того же типа
     * @param object объект, в который необходимо скопировать состояние
     */
    virtual void copyTo(T &object) = 0;
};


} } }

#endif // ICLONEABLE_H
