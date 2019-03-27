#include <iostream>

#include "ConsoleLogger.h"

using namespace energy::logs;

ConsoleLogger::ConsoleLogger(const ILogMessageFormatter *messageFormatter) :
    ILogger(messageFormatter)
{

}

void ConsoleLogger::info(const char *message) const
{
    printMessage("INFO", message);
}

void ConsoleLogger::debug(const char *message) const
{
    printMessage("DEBUG", message);
}

void ConsoleLogger::warning(const char *message) const
{
    printMessage("WARNING", message);
}

void ConsoleLogger::error(const char *message) const
{
    printMessage("ERROR", message);
}

void ConsoleLogger::trace(const char *message) const
{
    printMessage("TRACE", message);
}

void ConsoleLogger::printMessage(const char *channel, const char *message) const
{
    std::cout << _messageFormatter->formatMessage(channel, message);
}
