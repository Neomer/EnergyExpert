#ifndef TYPECASTINGEXCEPTION_H
#define TYPECASTINGEXCEPTION_H

#include <exception>

namespace energy { namespace core { namespace exceptions {

class TypeCastingException : public std::exception
{
public:
    explicit TypeCastingException();
    explicit TypeCastingException(const char *message);
    virtual ~TypeCastingException() noexcept = default;

    virtual const char* what() const noexcept { return _message; }

private:
    const char *_message;
};

} } }

#endif // TYPECASTINGEXCEPTION_H
