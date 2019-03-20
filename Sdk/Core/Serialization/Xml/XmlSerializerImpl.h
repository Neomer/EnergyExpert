#ifndef XMLSERIALIZERIMPL_H
#define XMLSERIALIZERIMPL_H

#include <Core/Serialization/ISerializer.h>
#include <Core/Serialization/Xml/XmlNode.h>
#include <Core/Serialization/Xml/IXmlDecorator.h>

namespace energy { namespace core { namespace serialization { namespace xml {

/**
 * @brief Базовый сериализатор для XML объектов.
 * Позволяет производить сериализацию и десериализацию XML-документов в строку.
 */
class SDKSHARED_EXPORT XmlSerializerImpl : public ISerializer
{
public:
    /**
     * @brief Базовый сериализатор для XML объектов.
     * @param tagNameDecorator Декоратор для имен тэгов.
     * @param attributeNameDecorator Декоратор для имен атрибутов.
     */
    XmlSerializerImpl(const IXmlDecorator *tagNameDecorator,
                      const IXmlDecorator *attributeNameDecorator);

    // ISerializer interface
public:
    /**
     * @brief Сериализует объект XmlObject.
     * @param object Экземпляр класс XmlObject.
     */
    virtual std::string serialize(const ISerializable *object) const override;
    virtual void deserialize(ISerializable *object, const std::string &data) override;

private:
    void serializeAttributes(std::stringstream &stream, const XmlNode *node) const;
    void serializeNode(std::stringstream &stream, const XmlNode *node) const;

    const IXmlDecorator *_tagNameDecorator, *_attributeNameDecorator;
};

} } } }

#endif // XMLSERIALIZERIMPL_H
