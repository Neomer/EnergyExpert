#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include <exception>

namespace energy { namespace exceptions {

#include <Sdk/export.h>

/**
 * @brief Исключение ввода-вывода.
 * Вызывается в следующих ситуациях:
 * - Недоступность устройства ввода-вывода
 * - Ошибка чтения-записи
 * - Недостаток прав доступа для операции чтения-записи
 */
class SDKSHARED_EXPORT IOException : public std::exception
{
public:
    IOException();
    IOException(const char *message);
    virtual ~IOException() noexcept = default;

    virtual const char* what() const noexcept { return _message; }

private:
    const char *_message;
};

} }


#endif // IOEXCEPTION_H
