#ifndef XMLOBJECT_H
#define XMLOBJECT_H

#include <Core/Serialization/Xml/XmlNode.h>
#include <Core/Serialization/Xml/IXmlSerializable.h>

namespace energy { namespace core { namespace serialization { namespace xml {

/**
 * @brief XML объект.
 */
class SDKSHARED_EXPORT XmlObject
{
public:
    XmlObject();
    /**
     * @brief Корневой узел объекта.
     * @return Константная ссылка на корневой узел
     */
    const XmlNode &getRootNode_const() const;
    /**
     * @brief Корневой узел объекта.
     * @return Ссылка на корневой узел
     */
    XmlNode &getRootNode();

private:
    XmlNode _rootNode;
};

} } } }

#endif // XMLOBJECT_H
