#ifndef IXMLDECORATOR_H
#define IXMLDECORATOR_H

#include <string>

namespace energy { namespace core { namespace serialization { namespace xml {

class IXmlDecorator
{
public:
    IXmlDecorator() = default;
    virtual ~IXmlDecorator() = default;

    virtual void decorate(std::stringstream &stream, const char *data) const = 0;
};

} } } }

#endif // IXMLDECORATOR_H
