#include "FileLogger.h"

#include <Sdk/Core/Data/BufferedWriteFile.h>

using namespace energy::core::data;
using namespace energy::logs;

#define CACHE_SIZE      10240

FileLogger::FileLogger(const char *filename, const ILogMessageFormatter *messageFormatter) :
    ILogger(messageFormatter)
{
    _file = new BufferedWriteFile(CACHE_SIZE, filename);
    _file->open(BufferedWriteFile::Append);
}

FileLogger::FileLogger(const char *filename, size_t cacheSize, const ILogMessageFormatter *messageFormatter) :
    ILogger(messageFormatter)
{
    _file = new BufferedWriteFile(cacheSize, filename);
    _file->open(BufferedWriteFile::Append);
}

FileLogger::~FileLogger()
{
    delete _file;
}

void FileLogger::info(const char *message)
{
    writeToFile("INFO", message);
}

void FileLogger::debug(const char *message)
{
    writeToFile("DEBUG", message);
}

void FileLogger::warning(const char *message)
{
    writeToFile("WARNING", message);
}

void FileLogger::error(const char *message)
{
    writeToFile("ERROR", message);
}

void FileLogger::trace(const char *message)
{
    writeToFile("TRACE", message);
}

void FileLogger::writeToFile(const char *channel, const char *message) const
{
    _file->write(_messageFormatter->formatMessage(channel, message).c_str());
}
