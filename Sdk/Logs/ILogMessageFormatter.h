#ifndef ILOGMESSAGEFORMATTER_H
#define ILOGMESSAGEFORMATTER_H

#include <string>

namespace energy::logs {

/**
 * @brief Интерфейс для классов, выполняющих форматирование строки-записи в лог.
 */
class ILogMessageFormatter
{
public:
    ILogMessageFormatter() = default;
    virtual ~ILogMessageFormatter() = default;

    /**
     * @brief Отформатировать строку для записи в лог
     * @param channel Канал для логирования
     * @param message Сообщение в лог
     * @return Отформатированная строка, готовая для записи в лог.
     */
    virtual std::string formatMessage(const char *channel, const char *message) const = 0;
};

}

#endif // ILOGMESSAGEFORMATTER_H
