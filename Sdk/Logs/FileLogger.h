#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <Sdk/export.h>

#include <Sdk/Logs/ILogger.h>
#include <Sdk/Core/Data/File.h>

namespace energy::logs {

/**
 * @brief Логер, пишущий в файл.
 */
class SDKSHARED_EXPORT FileLogger : public ILogger
{
public:
    explicit FileLogger(const char* filename, const ILogMessageFormatter *messageFormatter);
    explicit FileLogger(const char* filename, size_t cacheSize, const ILogMessageFormatter *messageFormatter);
    virtual ~FileLogger() override;

    // ILogger interface
public:
    virtual void info(const char *message) override;
    virtual void debug(const char *message) override;
    virtual void warning(const char *message) override;
    virtual void error(const char *message) override;
    virtual void trace(const char *message) override;

private:
    void writeToFile(const char *channel, const char *message) const;

    energy::core::data::File *_file;
};

}

#endif // FILELOGGER_H
