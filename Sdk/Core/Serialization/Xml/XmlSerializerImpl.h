#ifndef XMLSERIALIZERIMPL_H
#define XMLSERIALIZERIMPL_H

#include <export.h>
#include <Core/Serialization/ISerializer.h>

namespace energy { namespace core { namespace serialization { namespace xml {

class SDKSHARED_EXPORT XmlSerializerImpl : public ISerializer
{
public:
    XmlSerializerImpl();

    // ISerializer interface
public:
    virtual std::string serialize(const ISerializable *object) const override;
    virtual void deserialize(ISerializable *object, std::string &data) override;
};

} } } }

#endif // XMLSERIALIZERIMPL_H
