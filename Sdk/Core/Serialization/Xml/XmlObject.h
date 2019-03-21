#ifndef XMLOBJECT_H
#define XMLOBJECT_H

#include <Sdk/Core/Serialization/Xml/XmlNode.h>
#include <Sdk/Core/Serialization/Xml/IXmlSerializable.h>

namespace energy { namespace core { namespace serialization { namespace xml {

/**
 * @brief XML объект.
 */
class SDKSHARED_EXPORT XmlObject : public IXmlSerializable
{
public:
    XmlObject();
    XmlObject(XmlNode *root);
    /**
     * @brief Корневой узел объекта.
     * @return Константная ссылка на корневой узел
     */
    const XmlNode *getRootNode_const() const;
    /**
     * @brief Корневой узел объекта.
     * @return Ссылка на корневой узел
     */
    XmlNode *getRootNode();
    /**
     * @brief Проверяет есть ли в документе хоть один тэг
     */
    bool isEmpty() const;

private:
    XmlNode *_rootNode;
};

} } } }

#endif // XMLOBJECT_H
