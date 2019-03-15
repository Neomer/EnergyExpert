#ifndef JSONVALUE_H
#define JSONVALUE_H

#include <export.h>
#include <memory>
#include <variant>
#include <string.h>

#include <Core/Types/IStringable.h>

namespace energy { namespace core { namespace serialization { namespace json {

/**
 * @brief Значение поля объекта Json.
 */
class SDKSHARED_EXPORT JsonValue : public energy::core::types::IStringable
{
public:
    enum ValueType {
        Object,
        Array,
        Number,
        String,
        Boolean
    };

    JsonValue(ValueType type);
    virtual ~JsonValue() = default;

    ValueType objectType() const { return _type; }

    template<typename T>
    const T asType() const {
        return static_cast<T>(*_value);
    }

    template<typename T>
    T asType() {
        return static_cast<T>(*_value);
    }

    std::string asString() const {
        return std::string(_value);
    }

    uint32_t asUInt32() const {
        return asType<uint32_t>();
    }

    int32_t asInt32() const {
        return asType<int32_t>();
    }

    /**
     * @brief value<T>() устанавливает значение для свойства. Использовать только для простых типов, либо при передаче по значению.
     * Использование данного метода для установки значения по указателю вызовет некорректное поведение.
     * @param value новое значение
     */
    template<typename T>
    void value(T value) {
        allocateSpaceIfNeedeed(sizeof(T));
        memcpy(_value, &value, sizeof(T));
    }

    void value(const char *value) {
        size_t len = strlen(value) + 1;
        allocateSpaceIfNeedeed(len);
        memcpy(_value, value, len);
    }

    size_t size() const { return _size; }

    void erase();

private:
    inline void allocateSpaceIfNeedeed(size_t size)
    {
        if (size <= this->size()) {
            return;
        }
        erase();
        _value = new char[size];
        _size = size;
    }

    ValueType _type;
    char* _value;
    size_t _size;

    // IStringable interface
public:
    virtual std::string toString() const override;
    virtual void toString(std::string &buffer) const override;
};

} } } }

#endif // JSONVALUE_H
