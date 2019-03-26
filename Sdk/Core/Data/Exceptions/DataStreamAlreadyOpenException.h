#ifndef DATASTREAMALREADYOPENEXCEPTION_H
#define DATASTREAMALREADYOPENEXCEPTION_H

#include <Sdk/Core/Exceptions/IOException.h>

namespace energy { namespace exceptions {

class DataStreamAlreadyOpenException : public IOException
{
public:
    explicit DataStreamAlreadyOpenException();
    explicit DataStreamAlreadyOpenException(const char *message);
    virtual ~DataStreamAlreadyOpenException() noexcept = default;

    virtual const char* what() const noexcept { return _message; }

private:
    const char *_message;
};

} }

#endif // DATASTREAMALREADYOPENEXCEPTION_H
