#include <sstream>
#include <cstring>
#include <iomanip>

#include "DateTime.h"

#include <Core/Exceptions/NullPointerException.h>

#define SECS_IN_MINUTE          60
#define SECS_IN_HOUR            3600
#define SECS_IN_DAY             86400

using namespace energy::exceptions;
using namespace energy::core::types;

DateTime::DateTime() :
    _time{ std::time(nullptr) },
    _format{ "Y-M-D H:I:S" }
{
    _tm = std::gmtime(&_time);
}

DateTime::DateTime(time_t secondsSinceEpoch) :
    _time{ secondsSinceEpoch },
    _format{ "Y-M-D H:I:S" }
{
    _tm = std::gmtime(&_time);
}

DateTime::DateTime(const DateTime &other) :
    _time{ other._time }
{
    _tm = std::gmtime(&_time);
}

DateTime::~DateTime()
{
    delete _tm;
}

uint8_t DateTime::DaysInMonth(uint8_t month, uint16_t year)
{
    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return year % 4 ? 28 : 29;
    }
    return 0;
}

void DateTime::addSeconds(int secs)
{
    _time += secs;
}

void DateTime::addMinutes(int minutes)
{
    _time += minutes * SECS_IN_MINUTE;
}

void DateTime::addHours(int hours)
{
    _time += hours * SECS_IN_HOUR;
}

void DateTime::addDays(int days)
{
    _time += days * SECS_IN_DAY;
}

uint16_t DateTime::getYear() const
{
    return static_cast<uint8_t>(_tm->tm_year);
}

uint8_t DateTime::getMonth() const
{
    return static_cast<uint8_t>(_tm->tm_mon + 1);
}

uint8_t DateTime::getDay() const
{
    return static_cast<uint8_t>(_tm->tm_mday);
}

uint8_t DateTime::getHours() const
{
    return static_cast<uint8_t>(_time % SECS_IN_DAY / SECS_IN_HOUR);
}

uint8_t DateTime::getMinutes() const
{
    return static_cast<uint8_t>(_time % SECS_IN_HOUR / SECS_IN_MINUTE);
}

uint8_t DateTime::getSeconds() const
{
    return _time % SECS_IN_MINUTE;
}

time_t DateTime::getSecondsSinceEpoch() const
{
    return _time;
}

uint32_t DateTime::getDaysSinceEpoch() const
{
    return static_cast<uint32_t>(_time / SECS_IN_DAY);
}

void DateTime::setFormat(const char *format)
{
    _format = format;
}

DateTime DateTime::operator=(const DateTime &other)
{
    this->_time = other._time;
    return *this;
}

bool DateTime::operator>(const DateTime &other) const
{
    return _time > other._time;
}

bool DateTime::operator>=(const DateTime &other) const
{
    return _time >= other._time;
}

bool DateTime::operator<(const DateTime &other) const
{
    return _time < other._time;
}

bool DateTime::operator<=(const DateTime &other) const
{
    return _time <= other._time;
}

bool DateTime::operator==(const DateTime &other) const
{
    return _time == other._time;
}

bool DateTime::operator!=(const DateTime &other) const
{
    return _time != other._time;
}

std::string DateTime::toString() const
{
    std::stringstream stream;
    toFormat(stream);
    return stream.str();
}



void DateTime::toString(std::string &buffer) const
{
    std::stringstream stream;
    toFormat(stream);
    buffer = stream.str();
}

DateTime DateTime::clone() const
{
    DateTime dt;
    dt._time = _time;
    return dt;
}

void DateTime::copyTo(DateTime &object)
{
    object._time = _time;
}

void DateTime::toFormat(std::stringstream &stream) const
{
    auto len = strlen(_format);
    for (size_t i = 0; i < len; ++i) {
        char c = _format[i];
        switch (c)
        {
            case 'Y': stream << std::setfill('0') << std::setw(4) << std::to_string(getYear()); break;
            case 'y': stream << std::to_string(getYear() % 100); break;
            case 'M': stream << std::setfill('0') << std::setw(2) << std::to_string(getMonth()); break;
            case 'm': stream << std::to_string(getMonth()); break;
            case 'D': stream << std::setfill('0') << std::setw(2) << std::to_string(getDay()); break;
            case 'd': stream << std::to_string(getDay()); break;
            case 'H': stream << std::setfill('0') << std::setw(2) << std::to_string(getHours()); break;
            case 'h': stream << std::to_string(getHours()); break;
            case 'I': stream << std::setfill('0') << std::setw(2) << std::to_string(getMinutes()); break;
            case 'i': stream << std::to_string(getMinutes()); break;
            case 'S': stream << std::setfill('0') << std::setw(2) << std::to_string(getSeconds()); break;
            case 's': stream << std::to_string(getSeconds()); break;
            default: stream << c; break;
        }
    }
}
