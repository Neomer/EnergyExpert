#ifndef DEFAULTLOGMESSAGEFORMATTER_H
#define DEFAULTLOGMESSAGEFORMATTER_H

#include "../export.h"
#include <Logs/ILogMessageFormatter.h>

namespace energy::logs {

class SDKSHARED_EXPORT DefaultLogMessageFormatter : public ILogMessageFormatter
{
public:
    DefaultLogMessageFormatter() = default;
    virtual ~DefaultLogMessageFormatter() override = default;

    // ILogMessageFormatter interface
public:
    virtual std::string formatMessage(const char *channel, const char *message) const override;
};

}

#endif // DEFAULTLOGMESSAGEFORMATTER_H
