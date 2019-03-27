#ifndef DATATIME_H
#define DATATIME_H

#include <inttypes.h>
#include <chrono>

#include <Sdk/Core/Types/ICloneable.h>
#include <Sdk/Core/Types/IStringable.h>

namespace energy::core::types {

/**
 * @brief Класс для работы с датой
 */
class SDKSHARED_EXPORT DateTime :
        public ICloneable<DateTime>,
        public IStringable
{
public:
    /**
     * @brief Создает объект с текущей датой/временем
     */
    DateTime();
    /**
     * @brief Создает объект для указанной даты
     * @param secondsSinceEpoch Количество секунд с начала эпохи
     */
    DateTime(time_t secondsSinceEpoch);
    DateTime(const DateTime &other);
    virtual ~DateTime() override;
    /**
     * @brief Возвращает количество дней в в месяце по его номеру.
     * @param month Номер месяца (0 - январь)
     * @param year Год (для проверки високосности)
     * @return Количество дней в указанном месяце
     */
    static uint8_t DaysInMonth(uint8_t month, uint16_t year);

    /**
     * @brief Добавить секунды
     * @param secs Количество секунд
     */
    void addSeconds(int secs);
    /**
     * @brief Добавить минуты
     * @param secs Количество минут
     */
    void addMinutes(int minutes);
    /**
     * @brief Добавить часы
     * @param secs Количество часов
     */
    void addHours(int hours);
    /**
     * @brief Добавить дни
     * @param secs Количество дней
     */
    void addDays(int days);
    /**
     * @brief Возвращает год
     */
    uint16_t getYear() const;
    /**
     * @brief Возвращает месяц
     */
    uint8_t getMonth() const;
    /**
     * @brief Возвращает день
     */
    uint8_t getDay() const;
    /**
     * @brief Возвращает час
     */
    uint8_t getHours() const;
    /**
     * @brief Возвращает минуту
     */
    uint8_t getMinutes() const;
    /**
     * @brief Возвращает секунду
     */
    uint8_t getSeconds() const;
    /**
     * @brief Возвращает количество секунд с начала эпохи
     */
    time_t getSecondsSinceEpoch() const;
    /**
     * @brief Возвращает количество дней с начала эпохи
     */
    uint32_t getDaysSinceEpoch() const;
    /**
     * @brief Устанавливает формат для вывода даты/времени в строку.
     * @param format Y - год в формате 0000
     * y - год в формате 00
     * M - месяц в формате 00
     * m - месяц без выравнивающих нулей
     * D - день в формате 00
     * d - день без выравнивающих нулей
     * H - час в формате 00
     * h - час без выравнивающих нулей
     * I - минута в форме 00
     * i - минута без выравнивающих нулей
     * S - секунда в формате 00
     * s - секунда без выравнивающих нулей
     */
    void setFormat(const char *format);

    DateTime operator=(const DateTime &other);
    bool operator>(const DateTime &other) const;
    bool operator>=(const DateTime &other) const;
    bool operator<(const DateTime &other) const;
    bool operator<=(const DateTime &other) const;
    bool operator==(const DateTime &other) const;
    bool operator!=(const DateTime &other) const;

    // IStringable interface
public:
    virtual std::string toString() const override;
    virtual void toString(std::string &buffer) const override;

    // ICloneable interface
public:
    virtual DateTime clone() const override;
    virtual void copyTo(DateTime &object) override;

private:
    void toFormat(std::stringstream &stream) const;

    std::time_t _time;
    const char *_format;
    tm *_tm;
};

}


#endif // DATATIME_H
