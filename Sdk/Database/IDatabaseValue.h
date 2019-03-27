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
 * @brief Значение поля выборки из таблицы базы данных.
 */
class IDatabaseValue : public energy::core::types::IStringable
{
    INTERFACE(IDatabaseValue);

public:
    /**
     * @brief Представить значение как тип uint8_t
     * @throw TypeCastingException не удалось привести значение к данному типу
     */
    virtual uint8_t asUInt8() const = 0;
    /**
     * @brief Представить значение как тип uint16_t
     * @throw TypeCastingException не удалось привести значение к данному типу
     */
    virtual uint16_t asUInt16() const = 0;
    /**
     * @brief Представить значение как тип uint32_t
     * @throw TypeCastingException не удалось привести значение к данному типу
     */
    virtual uint32_t asUInt32() const = 0;
    /**
     * @brief Представить значение как тип uint64_t
     * @throw TypeCastingException не удалось привести значение к данному типу
     */
    virtual uint64_t asUInt64() const = 0;

    /**
     * @brief Представить значение как тип int8_t
     * @throw TypeCastingException не удалось привести значение к данному типу
     */
    virtual int8_t asInt8() const = 0;
    /**
     * @brief Представить значение как тип int16_t
     * @throw TypeCastingException не удалось привести значение к данному типу
     */
    virtual int16_t asInt16() const = 0;
    /**
     * @brief Представить значение как тип int32_t
     * @throw TypeCastingException не удалось привести значение к данному типу
     */
    virtual int32_t asInt32() const = 0;
    /**
     * @brief Представить значение как тип int64_t
     * @throw TypeCastingException не удалось привести значение к данному типу
     */
    virtual int64_t asInt64() const = 0;

    /**
     * @brief Представить значение как тип float
     * @throw TypeCastingException не удалось привести значение к данному типу
     */
    virtual float asFloat() const = 0;
    /**
     * @brief Представить значение как тип double
     * @throw TypeCastingException не удалось привести значение к данному типу
     */
    virtual double asDouble() const = 0;

    /**
     * @brief Представить значение как строку
     * @throw TypeCastingException не удалось привести значение к данному типу
     */
    virtual std::string asString() const = 0;
    /**
     * @brief Представить значение как тип bool
     * @throw TypeCastingException не удалось привести значение к данному типу
     */
    virtual bool asBool() const = 0;

    /**
     * @brief Представить значение как тип идентификатор
     * @throw TypeCastingException не удалось привести значение к данному типу
     */
    virtual energy::core::types::Uuid asUuid() const = 0;
    /**
     * @brief Представить значение как дату/время
     * @throw TypeCastingException не удалось привести значение к данному типу
     */
    virtual energy::core::types::DateTime asDateTime() const = 0;
};

} }

#endif // IDATABASEVALUE_H
