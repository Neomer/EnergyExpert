#ifndef ILOGGER_H
#define ILOGGER_H

#include <Logs/ILogMessageFormatter.h>

namespace energy::logs {

/**
 * @brief Интерфейс для классов, выполняющих логирование.
 */
class ILogger
{
public:
    ILogger(const ILogMessageFormatter *messageFormatter);
    virtual ~ILogger() = default;

    /**
     * @brief Логирование в информационный канал
     * @param message
     */
    virtual void info(const char *message) = 0;
    virtual void debug(const char *message) = 0;
    virtual void warning(const char *message) = 0;
    virtual void error(const char *message) = 0;
    virtual void trace(const char *message) = 0;

protected:
    const ILogMessageFormatter *_messageFormatter;
};

}

#endif // ILOGGER_H
