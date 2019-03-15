#ifndef UUID_H
#define UUID_H

#include <string>
#include <inttypes.h>

#include <export.h>
#include <Core/Types/IStringable.h>
#include <Core/Types/ICloneable.h>

namespace energy { namespace core { namespace types {

/**
 * @brief Uuid класс, позволяющий работать с UUID.
 */
class SDKSHARED_EXPORT Uuid final :
        public IStringable,
        public ICloneable<Uuid>
{
public:
    /**
     * @brief Создает Uuid по его строковому представлению
     * @param string Строка с Uuid
     * @throw throw std::invalid_argument не удалось обработать переданную строку. Возможно, что строка неверного формата.
     */
    Uuid(const std::string &string);
    /**
     * @brief Создает Uuid по его строковому представлению
     * @param data строка с Uuid
     */
    Uuid(const char *data);
    /**
     * @brief Создает Uuid через передачу инициирующих байт.
     * @param Первые 4 байта значения
     * @param Вторые 4 байта значения
     * @param Третьи 4 байта значения
     * @param Четвертые 4 байта значения
     */
    Uuid(uint32_t dw1, uint32_t dw2, uint32_t dw3, uint32_t dw4);

    Uuid(const Uuid &other);

    ~Uuid() override = default;

    /**
     * @brief Создание нулевой Uuid
     * @return Возвращается пустой Uuid вида {00000000-0000-0000-0000-000000000000}
     */
    static Uuid Empty();
    /**
     * @brief Генерирует случайный Uuid.
     * @return Возвращается случайный Uuid.
     */
    static Uuid Random();

    /**
     * @brief clear приводит значение Uuid к нулевому
     */
    void clear();
    /**
     * @brief isEmpty проверяет нулевой ли Uuid
     * @return true, если Uuid нулевой
     */
    bool isEmpty() const;
    /**
     * @brief size возвращает размер структуры в байтах
     * @return
     */
    constexpr size_t size() const;
    /**
     * @brief isEquals сравнивает два Uuid
     * @param other Uuid для сравнения
     * @return true, если оба Uuid одинаковы
     */
    bool isEquals(const Uuid &other) const;

    bool operator==(const Uuid &other) const;
    bool operator!=(const Uuid &other) const;

    bool operator>(const Uuid &other) const;
    bool operator>=(const Uuid &other) const;

    bool operator<(const Uuid &other) const;
    bool operator<=(const Uuid &other) const;

private:
    Uuid();
    /**
     * @brief parseString парсит строку в объект Uuid
     * @param str строковое представление Uuid
     */
    void parseString(const std::string &str);

    uint32_t _dw[4];

    // IStringable interface
public:
    virtual std::string toString() const override;
    virtual void toString(std::string &buffer) const override;

    // ICloneable interface
public:
    virtual Uuid clone() const override;
    virtual void copyTo(Uuid &object) override;
};

} } }

#endif // UUID_H
