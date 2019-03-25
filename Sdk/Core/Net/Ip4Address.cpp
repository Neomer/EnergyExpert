#include <cstring>
#include <regex>
#include <string>

#include "Ip4Address.h"
#include <Sdk/Core/Exceptions/TypeCastingException.h>

using namespace energy::core::net;
using namespace energy::exceptions;

Ip4Address::Ip4Address()
{

}

Ip4Address::Ip4Address(const Ip4Address &other)
{
    memcpy(_data, other._data, 4);
}

Ip4Address &Ip4Address::operator =(const Ip4Address &other)
{
    memcpy(_data, other._data, 4);
    return *this;
}

Ip4Address Ip4Address::FromString(const std::string &str)
{
    Ip4Address result;
    std::regex reg("^(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})$");
    std::smatch match;
    if (std::regex_search(str, match, reg) && match.size() == 4) {
        for (uint8_t idx = 0; idx < 4; idx++) {
            int v = std::stoi(match.str(idx));
            if (v < 0 || v > 255) {
                throw TypeCastingException();
            }
            result._data[idx] = static_cast<uint8_t>(v);
        }
    }
    return result;
}
