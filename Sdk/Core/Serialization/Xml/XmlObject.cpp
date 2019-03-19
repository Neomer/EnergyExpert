#include "XmlObject.h"

using namespace energy::core::serialization::xml;

XmlObject::XmlObject() :
    _rootNode(static_cast<const char *>(""))
{

}

XmlNode &XmlObject::getRootNode()
{
    return _rootNode;
}

const XmlNode &XmlObject::getRootNode_const() const
{
    return _rootNode;
}
