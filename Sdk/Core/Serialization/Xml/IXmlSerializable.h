#ifndef IXMLSERIALIZABLE_H
#define IXMLSERIALIZABLE_H

#include <Core/Serialization/ISerializable.h>

namespace energy { namespace core { namespace serialization { namespace xml {

class IXmlSerializable : public ISerializable
{
public:
    IXmlSerializable();
    virtual ~IXmlSerializable() override = default;
};

} } } }

#endif // IXMLSERIALIZABLE_H
