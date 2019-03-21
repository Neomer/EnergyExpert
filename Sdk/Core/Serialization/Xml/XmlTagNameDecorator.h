#ifndef XMLTAGNAMEDECORATOR_H
#define XMLTAGNAMEDECORATOR_H

#include <Sdk/export.h>
#include <Sdk/Core/Serialization/Xml/IXmlDecorator.h>

namespace energy { namespace core { namespace serialization { namespace xml {

class SDKSHARED_EXPORT XmlTagNameDecorator : public IXmlDecorator
{
public:
    XmlTagNameDecorator() = default;
    virtual ~XmlTagNameDecorator() override = default;

    // IXmlDecorator interface
public:
    virtual void decorate(std::stringstream &stream, const char *data) const override;
};

} } } }

#endif // XMLTAGNAMEDECORATOR_H
