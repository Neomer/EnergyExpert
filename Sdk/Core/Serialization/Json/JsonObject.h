#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include <Sdk/export.h>

#include <unordered_map>
#include <deque>

#include <Sdk/Core/Serialization/Json/JsonValue.h>

namespace energy { namespace core { namespace serialization { namespace json {

/**
 * @brief Объект Json.
 */
class SDKSHARED_EXPORT JsonObject final : public JsonValue
{
public:
    JsonObject();

    JsonValue &operator[](const std::string &name);
    JsonValue &operator[](const char *name);

private:
    std::unordered_map<std::string, JsonValue *> _map;
};

} } } }

#endif // JSONOBJECT_H
