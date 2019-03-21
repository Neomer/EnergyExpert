#ifndef TYPECASTINGEXCEPTION_H
#define TYPECASTINGEXCEPTION_H

#include <exception>

#include <Sdk/export.h>

namespace energy { namespace exceptions {

/**
 * @brief Исключение приведения одного типа к другому.
 */
class SDKSHARED_EXPORT TypeCastingException : public std::exception
{
public:
    explicit TypeCastingException();
    explicit TypeCastingException(const char *message);
    virtual ~TypeCastingException() noexcept = default;

    virtual const char* what() const noexcept { return _message; }

private:
    const char *_message;
};

} }

#endif // TYPECASTINGEXCEPTION_H
