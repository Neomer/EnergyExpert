#ifndef ISERIALIZER_H
#define ISERIALIZER_H

#include <string>
#include <Core/Serialization/ISerializable.h>

namespace energy { namespace core { namespace serialization {

/**
 * @brief Общий интерфейс для всех сериализаторов
 */
class ISerializer
{
public:
    ISerializer() = default;
    virtual ~ISerializer() = default;

    /**
     * @brief Сериализует объект в строку
     * @param object Объект для сериализации
     * @return Строковое представление объекта
     */
    virtual std::string serialize(const ISerializable *object) const = 0;
    /**
     * @brief Десериализует объект из строки
     * @param object Объект для десериализации
     * @param data Строка для разбора
     */
    virtual void deserialize(ISerializable *object, const std::string &data) = 0;
};

} } }

#endif // ISERIALIZER_H
