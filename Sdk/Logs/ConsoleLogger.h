#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include <Logs/ILogger.h>
#include "../export.h"

namespace energy::logs {

class SDKSHARED_EXPORT ConsoleLogger : public ILogger
{
public:
    ConsoleLogger(const ILogMessageFormatter *messageFormatter);
    virtual ~ConsoleLogger() override = default;


    // ILogger interface
public:
    virtual void info(const char *message) override;
    virtual void debug(const char *message) override;
    virtual void warning(const char *message) override;
    virtual void error(const char *message) override;
    virtual void trace(const char *message) override;

private:
    void printMessage(const char *channel, const char *message) const;
};

}

#endif // CONSOLELOGGER_H
