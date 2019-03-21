#include <sstream>
#include <chrono>

#include "DefaultLogMessageFormatter.h"

using namespace energy::logs;

std::string DefaultLogMessageFormatter::formatMessage(const char *channel, const char *message) const
{
    std::stringstream stream;
    stream << "LOG: " << channel << " " << message << "\n";
    return stream.str();
}
