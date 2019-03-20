#include <string>
#include <sstream>

#include "AbstractFileConfiguration.h"

using namespace energy::core::configuration;
using namespace energy::core::exceptions;

AbstractFileConfiguration::AbstractFileConfiguration() :
    IConfiguration()
{

}

void AbstractFileConfiguration::open(const char *path)
{
    _message = path;

    _file = std::fopen(_message, "r");
    if (!_file) {
        throw IOException();
    }
    std::stringstream stream;
    while (!std::feof(_file)) {
        char buf[1024];
        auto len = std::fread(buf, 1, 1024, _file);
        buf[len] = 0;
        stream << buf;
    }
    std::fclose(_file);
    fileDataReady(stream.str());
}

void AbstractFileConfiguration::saveAndClose()
{
    std::fopen(_message, "w");
    std::fclose(_file);
}

void AbstractFileConfiguration::rejectAndClose()
{

}
