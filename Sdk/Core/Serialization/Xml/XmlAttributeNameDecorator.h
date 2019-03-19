#ifndef XMLATTRIBUTENAMEDECORATOR_H
#define XMLATTRIBUTENAMEDECORATOR_H

#include <export.h>
#include <Core/Serialization/Xml/IXmlDecorator.h>

namespace energy { namespace core { namespace serialization { namespace xml {

class SDKSHARED_EXPORT XmlAttributeNameDecorator : public IXmlDecorator
{
public:
    XmlAttributeNameDecorator() = default;
    virtual ~XmlAttributeNameDecorator() override = default;

    // IXmlDecorator interface
public:
    virtual void decorate(std::stringstream &stream, const char *data) const override;
};

} } } }

#endif // XMLATTRIBUTENAMEDECORATOR_H
