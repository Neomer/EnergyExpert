#include "XmlObject.h"

using namespace energy::core::serialization::xml;

XmlObject::XmlObject()
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
