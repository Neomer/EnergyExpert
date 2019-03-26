#include "XmlObject.h"

using namespace energy::core::serialization::xml;

XmlObject::XmlObject() :
    _rootNode{ nullptr }
{

}

XmlObject::XmlObject(XmlNode *root) :
    _rootNode{ root }
{

}

XmlNode *XmlObject::getRootNode()
{
    return _rootNode;
}

bool XmlObject::isEmpty() const
{
    return _rootNode == nullptr;
}

const XmlNode *XmlObject::getRootNode_const() const
{
    return _rootNode;
}
