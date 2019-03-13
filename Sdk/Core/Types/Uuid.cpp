#include "Uuid.h"

#include <string.h>
#include <memory>

using namespace energy::core::types;

Uuid::Uuid(const std::string &string)
{

}

Uuid::Uuid(const char *data)
{

}

Uuid::Uuid(const Uuid &other)
{
    memcpy(_dw, other._dw, size());
}

Uuid::Uuid()
{

}

Uuid Uuid::Empty()
{
    Uuid uid;
    uid.clear();
    return uid;
}

void Uuid::clear()
{
    memset(_dw, 0, size());
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
