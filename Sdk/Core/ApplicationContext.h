#ifndef APPLICATIONCONTEXT_H
#define APPLICATIONCONTEXT_H

#include <Sdk/export.h>
#include <Sdk/singleton.h>

#include <Sdk/Logs/ILogger.h>
#include <Sdk/Database/IDatabaseConnectionsProvider.h>

namespace energy::core {

class SDKSHARED_EXPORT ApplicationContext
{
    SINGLETON(ApplicationContext)

private:
    ApplicationContext();
    ~ApplicationContext();

public:
    void init();

    const energy::logs::ILogger *getDefaultLogger();
    const energy::logs::ILogger *getReservedLogger();

private:
    energy::logs::ILogger *_defaultLogger, *_reservedLogger;
    energy::logs::ILogMessageFormatter *_logMessageFormatter;
    energy::database::IDatabaseConnectionsProvider *_databaseConnectionProvider;
};

}

#endif // APPLICATIONCONTEXT_H
