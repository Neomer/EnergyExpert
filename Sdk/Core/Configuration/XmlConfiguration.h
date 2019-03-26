#ifndef XMLCONFIGURATION_H
#define XMLCONFIGURATION_H

#include <Sdk/Core/Configuration/AbstractFileConfiguration.h>
#include <Sdk/Core/Serialization/Xml/XmlObject.h>
#include <Sdk/Core/Serialization/ISerializer.h>

namespace energy { namespace core { namespace configuration {

class SDKSHARED_EXPORT XmlConfiguration : public AbstractFileConfiguration
{
public:
    XmlConfiguration(energy::core::serialization::ISerializer *serializer);
    virtual ~XmlConfiguration() override;

    // IConfiguration interface
public:
    virtual void write(const char *key, int value) override;
    virtual void write(const char *key, double value) override;
    virtual void write(const char *key, std::string &value) override;
    virtual void write(const char *key, const char *value) override;
    virtual void write(const char *key, const energy::core::types::IStringable *value) override;
    virtual int readInt(const char *key) const override;
    virtual double readDouble(const char *key) const override;
    virtual std::string readString(const char *key) const override;

    // AbstractFileConfiguration interface
protected:
    virtual void fileDataReady(const std::string &str) override;

private:
    energy::core::serialization::xml::XmlNode *getNode(const char *key);
    const energy::core::serialization::xml::XmlNode *getNode_const(const char *key) const;

    energy::core::serialization::xml::XmlObject _xmlObject;
    energy::core::serialization::ISerializer *_xmlSerializer;
};

} } }

#endif // XMLCONFIGURATION_H
