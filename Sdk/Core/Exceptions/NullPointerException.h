#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H

#include <exception>

namespace energy { namespace core { namespace exceptions {

class NullPointerException : public std::exception
{
public:
    explicit NullPointerException();
    explicit NullPointerException(const char *message);
    virtual ~NullPointerException() noexcept = default;

    virtual const char* what() const noexcept { return _message; }

private:
    const char *_message;
};

} } }

#endif // NULLPOINTEREXCEPTION_H
