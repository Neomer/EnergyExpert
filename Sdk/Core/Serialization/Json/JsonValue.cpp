#include "JsonValue.h"

using namespace energy::core::serialization::json;

JsonValue::JsonValue(ValueType type) :
    _type{ type },
    _value{ nullptr },
    _size{ 0 }
{

}

void JsonValue::erase()
{
    delete _value;
    _value = nullptr;
}

std::string JsonValue::toString() const
{
    return asString();
}

void JsonValue::toString(std::string &buffer) const
{
    buffer = asString();
}


