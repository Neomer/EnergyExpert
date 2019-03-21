#ifndef IDATABASEVALUE_H
#define IDATABASEVALUE_H

#include <inttypes.h>
#include <string>

#include <Sdk/Core/Types/Uuid.h>
#include <Sdk/Core/Types/DateTime.h>
#include <Sdk/Core/Types/IStringable.h>

namespace energy { namespace database {

class IDatabaseValue : public energy::core::types::IStringable
{
public:
    IDatabaseValue() = default;
    virtual ~IDatabaseValue() = default;

    virtual uint8_t asUInt8() const = 0;
    virtual uint16_t asUInt16() const = 0;
    virtual uint32_t asUInt32() const = 0;
    virtual uint64_t asUInt64() const = 0;

    virtual int8_t asInt8() const = 0;
    virtual int16_t asInt16() const = 0;
    virtual int32_t asInt32() const = 0;
    virtual int64_t asInt64() const = 0;

    virtual float asFloat() const = 0;
    virtual double asDouble() const = 0;

    virtual std::string asString() const = 0;
    virtual bool asBool() const = 0;

    virtual energy::core::types::Uuid asUuid() const = 0;
    virtual energy::core::types::DateTime asDateTime() const = 0;
};

} }

#endif // IDATABASEVALUE_H
