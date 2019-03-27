#include "ILogger.h"

using namespace energy::logs;

ILogger::ILogger(const ILogMessageFormatter *messageFormatter) :
    _messageFormatter{messageFormatter}
{

}

void ILogger::info(const energy::core::types::IStringable &stringable) const
{
    info(stringable.toString().c_str());
}

void ILogger::debug(const energy::core::types::IStringable &stringable) const
{
    debug(stringable.toString().c_str());
}

void ILogger::warning(const energy::core::types::IStringable &stringable) const
{
    warning(stringable.toString().c_str());
}

void ILogger::error(const energy::core::types::IStringable &stringable) const
{
    error(stringable.toString().c_str());
}

void ILogger::trace(const energy::core::types::IStringable &stringable) const
{
    trace(stringable.toString().c_str());
}
