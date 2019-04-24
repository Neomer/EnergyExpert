#ifndef PUGIXMLSERIALIZER_H
#define PUGIXMLSERIALIZER_H

#include <Sdk/Core/Serialization/ISerializer.h>
#include <pugixml.hpp>

namespace energy::core::serialization {

class PugiXmlSerializer : public ISerializer
{
public:
    PugiXmlSerializer();
    ~PugiXmlSerializer() override;

    // ISerializer interface
public:
    virtual std::string serialize(const ISerializable *object) const override;
    virtual void deserialize(ISerializable *object, const std::string &data) override;
};

}


#endif // PUGIXMLSERIALIZER_H
