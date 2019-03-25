#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <inttypes.h>
#include <string>

#include <Sdk/export.h>
#include <Sdk/Core/Types/IStringable.h>

namespace energy::core::net {

class SDKSHARED_EXPORT Ip4Address :
        public energy::core::types::IStringable
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

    // IStringable interface
public:
    virtual std::string toString() const override;
    virtual void toString(std::string &buffer) const override;
};

}

#endif // IPADDRESS_H
