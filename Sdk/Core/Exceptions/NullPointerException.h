#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H

#include <exception>

#include <Sdk/export.h>

namespace energy { namespace exceptions {

/**
 * @brief Исключение вызывается всякий раз, когда происходит попытка использования нулевого указателя.
 * Эта ошибка означает, что использование переменной произошло раньше ее инициализации.
 */
class SDKSHARED_EXPORT NullPointerException : public std::exception
{
public:
    explicit NullPointerException();
    explicit NullPointerException(const char *message);
    virtual ~NullPointerException() noexcept = default;

    virtual const char* what() const noexcept { return _message; }

private:
    const char *_message;
};

} }

#endif // NULLPOINTEREXCEPTION_H
