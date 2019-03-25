#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <inttypes.h>
#include <string>

#include <Sdk/export.h>

namespace energy::core::net {

class SDKSHARED_EXPORT Ip4Address
{
public:
    Ip4Address();
    Ip4Address(const Ip4Address& other);
    Ip4Address &operator =(const Ip4Address& other);

    /**
     * @brief Формирует экземпляр класса из строки.
     * @param str Строка с адресом IP4
     * @throw energy::exceptions::TypeCastingException Не удалось строку преобразовать в Ip4Address.
     */
    static Ip4Address FromString(const std::string &str);

private:
    uint8_t _data[4];
};

}

#endif // IPADDRESS_H
