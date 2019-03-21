#include "ILogger.h"

using namespace energy::logs;

ILogger::ILogger(const ILogMessageFormatter *messageFormatter) :
    _messageFormatter{messageFormatter}
{

}
