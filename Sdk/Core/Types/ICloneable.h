#ifndef ICLONEABLE_H
#define ICLONEABLE_H

#include <export.h>

namespace energy { namespace core { namespace types {

/**
 * @brief ICloneable<T> интерфейс, реализации которого должны предоставлять копии самого себя.
 * T - тип, в который может быть склонирован исходный тип.
 */
template<typename T>
class SDKSHARED_EXPORT ICloneable {
public:
    ICloneable() = default;
    virtual ~ICloneable() = default;

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
