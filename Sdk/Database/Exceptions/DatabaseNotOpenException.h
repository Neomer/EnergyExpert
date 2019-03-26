#ifndef DATABASENOTOPENEXCEPTION_H
#define DATABASENOTOPENEXCEPTION_H

#include <Sdk/export.h>
#include <exception>

namespace energy { namespace exceptions {

class SDKSHARED_EXPORT DatabaseNotOpenException : public std::exception
{
public:
    explicit DatabaseNotOpenException();
    explicit DatabaseNotOpenException(const char *message);
    virtual ~DatabaseNotOpenException() noexcept = default;

    virtual const char* what() const noexcept { return _message; }

private:
    const char *_message;
};

} }


#endif // DATABASENOTOPENEXCEPTION_H
