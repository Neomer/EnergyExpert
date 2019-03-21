#ifndef ILOGMESSAGEFORMATTER_H
#define ILOGMESSAGEFORMATTER_H

#include <string>

namespace energy::logs {

class ILogMessageFormatter
{
public:
    ILogMessageFormatter() = default;
    virtual ~ILogMessageFormatter() = default;

    virtual std::string formatMessage(const char *channel, const char *message) const = 0;
};

}

#endif // ILOGMESSAGEFORMATTER_H
