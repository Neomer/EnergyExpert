#include "Uuid.h"

#include <string.h>
#include <memory>

using namespace energy::core::types;

Uuid::Uuid(const std::string &string)
{
    parseString(string);
}

Uuid::Uuid(const char *data)
{
    parseString(data);
}

Uuid::Uuid(uint32_t dw1, uint32_t dw2, uint32_t dw3, uint32_t dw4)
{
    _dw[0] = dw1; _dw[1] = dw2; _dw[2] = dw3; _dw[3] = dw4;
}

Uuid::Uuid(const Uuid &other)
{
    memcpy(_dw, other._dw, size());
}

Uuid::Uuid()
{

}

void Uuid::parseString(const std::string &str)
{
    //TODO: сделать корректный парсинг строк
}

std::string Uuid::toString() const
{
    // TODO: сделать корректное привидение к строке
    auto ret = std::string();
    ret.append(std::to_string(_dw[0]));
    ret.append(std::to_string(_dw[1]));
    ret.append(std::to_string(_dw[2]));
    ret.append(std::to_string(_dw[3]));
    return ret;
}

void Uuid::toString(std::string &buffer) const
{
    // TODO: сделать корректное привидение к строке
    buffer.clear();
    buffer.append(std::to_string(_dw[0]));
    buffer.append(std::to_string(_dw[1]));
    buffer.append(std::to_string(_dw[2]));
    buffer.append(std::to_string(_dw[3]));
}

Uuid Uuid::clone() const
{
    Uuid object;
    memcpy(object._dw, _dw, size());
    return object;
}

void Uuid::copyTo(Uuid &object)
{
    memcpy(object._dw, _dw, size());
}

Uuid Uuid::Empty()
{
    Uuid uid;
    uid.clear();
    return uid;
}

Uuid Uuid::Random()
{
    return Uuid();
}

void Uuid::clear()
{
    memset(_dw, 0, size());
}

bool Uuid::isEmpty() const
{
    for (auto idx = 0; idx < 4; ++idx) {
        if (_dw[idx]) {
            return false;
        }
    }
    return true;
}

constexpr size_t Uuid::size() const
{
    return sizeof(uint32_t) * 4;
}

bool Uuid::isEquals(const Uuid &other) const
{
    return memcmp(_dw, other._dw, size()) == 0;
}

bool Uuid::operator==(const Uuid &other) const
{
    return isEquals(other);
}

bool Uuid::operator!=(const Uuid &other) const
{
    return !isEquals(other);
}

bool Uuid::operator>(const Uuid &other) const
{
    return memcmp(_dw, other._dw, size()) > 0;
}

bool Uuid::operator>=(const Uuid &other) const
{
    return memcmp(_dw, other._dw, size()) >= 0;
}

bool Uuid::operator<(const Uuid &other) const
{
    return memcmp(_dw, other._dw, size()) < 0;
}

bool Uuid::operator<=(const Uuid &other) const
{
    return memcmp(_dw, other._dw, size()) <= 0;
}
