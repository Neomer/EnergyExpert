
#include <Sdk/Logs/DefaultLogMessageFormatter.h>
#include <Sdk/Logs/ConsoleLogger.h>
#include <Sdk/Logs/FileLogger.h>

#include "ApplicationContext.h"

using namespace energy::core;
using namespace energy::logs;

ApplicationContext::ApplicationContext() :
    _defaultLogger{ nullptr },
    _reservedLogger{ nullptr },
    _logMessageFormatter{ nullptr },
    _databaseConnectionProvider{ nullptr }
{

}

ApplicationContext::~ApplicationContext()
{
    delete _defaultLogger;
    delete _reservedLogger;
    delete _logMessageFormatter;
    delete _databaseConnectionProvider;
}

void ApplicationContext::init()
{
    _logMessageFormatter = new DefaultLogMessageFormatter();
    _defaultLogger = new FileLogger("main.log", _logMessageFormatter);
    _reservedLogger = new ConsoleLogger(_logMessageFormatter);
}

const ILogger *ApplicationContext::getDefaultLogger()
{
    return _defaultLogger;
}

const ILogger *ApplicationContext::getReservedLogger()
{
    return _reservedLogger;
}
