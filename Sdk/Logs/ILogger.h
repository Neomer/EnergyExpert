#ifndef ILOGGER_H
#define ILOGGER_H

#include <Sdk/Core/Types/IStringable.h>
#include <Sdk/Logs/ILogMessageFormatter.h>

namespace energy::logs {

/**
 * @brief Интерфейс для классов, выполняющих логирование.
 */
class SDKSHARED_EXPORT ILogger
{
public:
    ILogger(const ILogMessageFormatter *messageFormatter);
    virtual ~ILogger() = default;

    /**
     * @brief Логирование в информационный канал
     * @param message Сообщение
     */
    virtual void info(const char *message) const = 0;
    /**
     * @brief Логирование в информационный канал
     * @param message Объект, преобразуемые в строку
     */
    virtual void info(const energy::core::types::IStringable &stringable) const;

    /**
     * @brief Логирование в канал для дебага
     * @param message Сообщение
     */
    virtual void debug(const char *message) const = 0;
    /**
     * @brief Логирование в канал для дебага
     * @param message Объект, преобразуемые в строку
     */
    virtual void debug(const energy::core::types::IStringable &stringable) const;

    /**
     * @brief Логирование в канал предупреждений
     * @param message Сообщение
     */
    virtual void warning(const char *message) const = 0;
    /**
     * @brief Логирование в канал предупреждений
     * @param message Объект, преобразуемые в строку
     */
    virtual void warning(const energy::core::types::IStringable &stringable) const;
    /**
     * @brief Логирование в канал ошибок
     * @param message Сообщение
     */
    virtual void error(const char *message) const = 0;
    /**
     * @brief Логирование в канал ошибок
     * @param message Объект, преобразуемые в строку
     */
    virtual void error(const energy::core::types::IStringable &stringable) const;
    /**
     * @brief Логирование в канал трассировки
     * @param message Сообщение
     */
    virtual void trace(const char *message) const = 0;
    /**
     * @brief Логирование в канал трассировки
     * @param message Объект, преобразуемые в строку
     */
    virtual void trace(const energy::core::types::IStringable &stringable) const;

protected:
    const ILogMessageFormatter *_messageFormatter;
};

}

#endif // ILOGGER_H
