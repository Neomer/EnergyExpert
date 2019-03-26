#ifndef XMLATTRIBUTEDESTROYINGLISTENER_H
#define XMLATTRIBUTEDESTROYINGLISTENER_H

namespace energy::core::serialization::xml {

class XmlAttribute;

/**
 * @brief Интерфейс для классов, ожидающих начало уничтожения атрибута XML.
 * Реализуется в XmlNode, чтобы контролировать уничтожение своих атрибутов.
 */
class IXmlAttributeDestroyingListener
{
public:
    IXmlAttributeDestroyingListener() = default;
    virtual ~IXmlAttributeDestroyingListener() = default;

    virtual void onXmlAttributeDestroying(const XmlAttribute *xmlAttribute) = 0;

};

}

#endif // XMLATTRIBUTEDESTROYINGLISTENER_H
