#ifndef XMLVALUE_H
#define XMLVALUE_H

#include <string>

#include <Sdk/export.h>

namespace energy { namespace core { namespace serialization { namespace xml {

class XmlNode;

class SDKSHARED_EXPORT XmlValue
{
public:
    XmlValue(const void *value);

    const std::string &asText() const;

private:
    const void *_value;
};

} } } }

#endif // XMLVALUE_H
