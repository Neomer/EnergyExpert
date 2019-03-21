#ifndef POSTGRESQLDATABASEVALUE_H
#define POSTGRESQLDATABASEVALUE_H

#include <Sdk/Database/IDatabaseValue.h>

namespace energy::database {

class SDKSHARED_EXPORT PostgreSqlValue : public IDatabaseValue
{
public:
    using FakeDataType = void *;

    PostgreSqlValue(FakeDataType data);
    virtual ~PostgreSqlValue() override = default;

    // IStringable interface
public:
    virtual std::string toString() const override;
    virtual void toString(std::string &buffer) const override;

    // IDatabaseValue interface
public:
    virtual uint8_t asUInt8() const override;
    virtual uint16_t asUInt16() const override;
    virtual uint32_t asUInt32() const override;
    virtual uint64_t asUInt64() const override;
    virtual int8_t asInt8() const override;
    virtual int16_t asInt16() const override;
    virtual int32_t asInt32() const override;
    virtual int64_t asInt64() const override;
    virtual float asFloat() const override;
    virtual double asDouble() const override;
    virtual std::string asString() const override;
    virtual bool asBool() const override;
    virtual core::types::Uuid asUuid() const override;
    virtual core::types::DateTime asDateTime() const override;

private:
    FakeDataType _data;
};

}


#endif // POSTGRESQLDATABASEVALUE_H
