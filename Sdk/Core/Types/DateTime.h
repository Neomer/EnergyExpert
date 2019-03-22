#ifndef DATATIME_H
#define DATATIME_H

#include <inttypes.h>
#include <chrono>

#include <Core/Types/ICloneable.h>
#include <Core/Types/IStringable.h>

namespace energy::core::types {

class SDKSHARED_EXPORT DateTime :
        public ICloneable<DateTime>,
        public IStringable
{
public:
    DateTime();
    DateTime(time_t secondsSinceEpoch);
    DateTime(const DateTime &other);
    virtual ~DateTime() override;

    static uint8_t DaysInMonth(uint8_t month, uint16_t year);

    void addSeconds(int secs);
    void addMinutes(int minutes);
    void addHours(int hours);
    void addDays(int days);

    uint16_t getYear() const;
    uint8_t getMonth() const;
    uint8_t getDay() const;
    uint8_t getHours() const;
    uint8_t getMinutes() const;
    uint8_t getSeconds() const;

    time_t getSecondsSinceEpoch() const;
    uint32_t getDaysSinceEpoch() const;

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
