#ifndef DATASTREAMNOTOPENEXCEPTION_H
#define DATASTREAMNOTOPENEXCEPTION_H

#include <Sdk/Core/Exceptions/IOException.h>

namespace energy { namespace exceptions {


class DataStreamNotOpenException : public IOException
{
public:
    explicit DataStreamNotOpenException();
    explicit DataStreamNotOpenException(const char *message);
    virtual ~DataStreamNotOpenException() noexcept = default;

    virtual const char* what() const noexcept { return _message; }

private:
    const char *_message;
};


} }

#endif // DATASTREAMNOTOPENEXCEPTION_H
