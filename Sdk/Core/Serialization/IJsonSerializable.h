#ifndef IJSONSERIALIZABLE_H
#define IJSONSERIALIZABLE_H

#include <export.h>
#include <Core/Serialization/Json/JsonObject.h>

namespace energy { namespace core { namespace serialization {

/**
 * @brief Интерфейс для классов, способных сериализоваться в Json.
 */
class SDKSHARED_EXPORT IJsonSerializable {
public:
    IJsonSerializable() = default;
    virtual ~IJsonSerializable() = default;

    /**
     * @brief сериализует класс в Json объект.
     * @param object Json объект, в который необходимо сериализовать класс
     */
    virtual void toJsonObject(energy::core::serialization::json::JsonObject &object);
    /**
     * @brief десериализует класс из Json объекта.
     * @param object Json объект, из которого необходимо десериализовать класс
     */
    virtual void fromJsonObject(const energy::core::serialization::json::JsonObject &object);

};

} } }

#endif // IJSONSERIALIZABLE_H
