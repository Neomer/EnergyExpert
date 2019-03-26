#ifdef POSTGRESQL_SUPPORT

#include <string.h>
#include <cstring>

#include <Sdk/Core/Exceptions/TypeCastingException.h>

#include "PostgreSqlValue.h"

using namespace energy::database;
using namespace energy::core::types;
using namespace energy::exceptions;

PostgreSqlValue::PostgreSqlValue(FakeDataType data) :
    _data{ data }
{

}

std::string PostgreSqlValue::toString() const
{
    return static_cast<const char*>(_data);
}

void PostgreSqlValue::toString(std::string &buffer) const
{
    buffer = static_cast<const char*>(_data);
}

uint8_t PostgreSqlValue::asUInt8() const
{
    return static_cast<uint8_t>(std::stoul(static_cast<const char *>(_data)));
}

uint16_t PostgreSqlValue::asUInt16() const
{
    return static_cast<uint16_t>(std::stoul(static_cast<const char *>(_data)));
}

uint32_t PostgreSqlValue::asUInt32() const
{
    return static_cast<uint32_t>(std::stoul(static_cast<const char *>(_data)));
}

uint64_t PostgreSqlValue::asUInt64() const
{
    return static_cast<uint64_t>(std::stoull(static_cast<const char *>(_data)));
}

int8_t PostgreSqlValue::asInt8() const
{
    return static_cast<int8_t>(std::stol(static_cast<const char *>(_data)));
}

int16_t PostgreSqlValue::asInt16() const
{
    return static_cast<int16_t>(std::stol(static_cast<const char *>(_data)));
}

int32_t PostgreSqlValue::asInt32() const
{
    return static_cast<int32_t>(std::stol(static_cast<const char *>(_data)));
}

int64_t PostgreSqlValue::asInt64() const
{
    return static_cast<int64_t>(std::stoll(static_cast<const char *>(_data)));
}

float PostgreSqlValue::asFloat() const
{
    return std::stof(static_cast<const char *>(_data));
}

double PostgreSqlValue::asDouble() const
{
    return std::stod(static_cast<const char *>(_data));
}

std::string PostgreSqlValue::asString() const
{
    return static_cast<const char*>(_data);
}

bool PostgreSqlValue::asBool() const
{
    auto str = static_cast<char*>(_data);
    size_t len = strlen(str);
    for (size_t idx = 0; idx < len; ++idx) {
        str[len] = static_cast<char>(tolower(str[len]));
    }
    if (!strcmp(str, "f") || !strcmp(str, "false") || !strcmp(str, "0")) {
        return false;
    } else if (!strcmp(str, "t") || !strcmp(str, "true") || !strcmp(str, "1")) {
        return true;
    } else {
        throw TypeCastingException();
    }
}

energy::core::types::Uuid PostgreSqlValue::asUuid() const
{
    return Uuid(static_cast<const char *>(_data));
}

energy::core::types::DateTime PostgreSqlValue::asDateTime() const
{
    //TODO: реализовать получение даты
}

#endif
