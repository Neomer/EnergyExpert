#include "JsonObject.h"

using namespace energy::core::serialization::json;

JsonObject::JsonObject() :
    JsonValue(JsonValue::Object)
{

}

JsonValue &JsonObject::operator[](const std::string &name)
{
    JsonValue *result = nullptr;
    auto it = _map.find(name);
    if (it == _map.end()) {
        result = new JsonValue(JsonValue::Object);
        _map[name] = result;
    } else {
        result = it->second;
    }
    return *result;
}


JsonValue &JsonObject::operator[](const char *name)
{
    return operator[](std::string(name));
}
