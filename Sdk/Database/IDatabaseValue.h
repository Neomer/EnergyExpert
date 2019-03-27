#ifndef IDATABASEVALUE_H
#define IDATABASEVALUE_H

#include <inttypes.h>
#include <string>

#include <Sdk/singleton.h>
#include <Sdk/Core/Types/Uuid.h>
#include <Sdk/Core/Types/DateTime.h>
#include <Sdk/Core/Types/IStringable.h>

namespace energy { namespace database {

/**
 * @brief �������� ���� ������� �� ������� ���� ������.
 */
class IDatabaseValue : public energy::core::types::IStringable
{
    INTERFACE(IDatabaseValue);

public:
    /**
     * @brief ����������� �������� ��� ��� uint8_t
     * @throw TypeCastingException �� ������� �������� �������� � ������� ����
     */
    virtual uint8_t asUInt8() const = 0;
    /**
     * @brief ����������� �������� ��� ��� uint16_t
     * @throw TypeCastingException �� ������� �������� �������� � ������� ����
     */
    virtual uint16_t asUInt16() const = 0;
    /**
     * @brief ����������� �������� ��� ��� uint32_t
     * @throw TypeCastingException �� ������� �������� �������� � ������� ����
     */
    virtual uint32_t asUInt32() const = 0;
    /**
     * @brief ����������� �������� ��� ��� uint64_t
     * @throw TypeCastingException �� ������� �������� �������� � ������� ����
     */
    virtual uint64_t asUInt64() const = 0;

    /**
     * @brief ����������� �������� ��� ��� int8_t
     * @throw TypeCastingException �� ������� �������� �������� � ������� ����
     */
    virtual int8_t asInt8() const = 0;
    /**
     * @brief ����������� �������� ��� ��� int16_t
     * @throw TypeCastingException �� ������� �������� �������� � ������� ����
     */
    virtual int16_t asInt16() const = 0;
    /**
     * @brief ����������� �������� ��� ��� int32_t
     * @throw TypeCastingException �� ������� �������� �������� � ������� ����
     */
    virtual int32_t asInt32() const = 0;
    /**
     * @brief ����������� �������� ��� ��� int64_t
     * @throw TypeCastingException �� ������� �������� �������� � ������� ����
     */
    virtual int64_t asInt64() const = 0;

    /**
     * @brief ����������� �������� ��� ��� float
     * @throw TypeCastingException �� ������� �������� �������� � ������� ����
     */
    virtual float asFloat() const = 0;
    /**
     * @brief ����������� �������� ��� ��� double
     * @throw TypeCastingException �� ������� �������� �������� � ������� ����
     */
    virtual double asDouble() const = 0;

    /**
     * @brief ����������� �������� ��� ������
     * @throw TypeCastingException �� ������� �������� �������� � ������� ����
     */
    virtual std::string asString() const = 0;
    /**
     * @brief ����������� �������� ��� ��� bool
     * @throw TypeCastingException �� ������� �������� �������� � ������� ����
     */
    virtual bool asBool() const = 0;

    /**
     * @brief ����������� �������� ��� ��� �������������
     * @throw TypeCastingException �� ������� �������� �������� � ������� ����
     */
    virtual energy::core::types::Uuid asUuid() const = 0;
    /**
     * @brief ����������� �������� ��� ����/�����
     * @throw TypeCastingException �� ������� �������� �������� � ������� ����
     */
    virtual energy::core::types::DateTime asDateTime() const = 0;
};

} }

#endif // IDATABASEVALUE_H
