#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include <exception>

namespace energy { namespace core { namespace exceptions {

/**
 * @brief Исключение ввода-вывода.
 * Вызывается в следующих ситуациях:
 * - Недоступность устройства ввода-вывода
 * - Ошибка чтения-записи
 * - Недостаток прав доступа для операции чтения-записи
 */
class IOException : public std::exception
{
public:
    explicit IOException();
    explicit IOException(const char *message);
    virtual ~IOException() noexcept = default;

    virtual const char* what() const noexcept { return _message; }

private:
    const char *_message;
};

} } }


#endif // IOEXCEPTION_H
