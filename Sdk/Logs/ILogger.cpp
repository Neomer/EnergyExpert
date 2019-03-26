#include "ILogger.h"

using namespace energy::logs;

ILogger::ILogger(const ILogMessageFormatter *messageFormatter) :
    _messageFormatter{messageFormatter}
{

}

void ILogger::info(const energy::core::types::IStringable &stringable)
{
    info(stringable.toString().c_str());
}

void ILogger::debug(const energy::core::types::IStringable &stringable)
{
    debug(stringable.toString().c_str());
}

void ILogger::warning(const energy::core::types::IStringable &stringable)
{
    warning(stringable.toString().c_str());
}

void ILogger::error(const energy::core::types::IStringable &stringable)
{
    error(stringable.toString().c_str());
}

void ILogger::trace(const energy::core::types::IStringable &stringable)
{
    trace(stringable.toString().c_str());
}
