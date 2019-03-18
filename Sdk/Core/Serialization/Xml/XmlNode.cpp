#include <algorithm>
#include <string.h>

#include "XmlNode.h"

using namespace energy::core::serialization::xml;

XmlNode::XmlNode(const XmlNode *parent) :
    _parent{ parent }
{

}

const XmlNode *XmlNode::getParentNode() const
{
    return _parent;
}

const char *XmlNode::getName() const
{
    return _name;
}

void XmlNode::setName(const char *value)
{
    _name = value;
}

const XmlAttribute *XmlNode::getAttribute(const char *name) const
{
    auto it = std::find_if(_attr.begin(), _attr.end(), [name](const XmlAttribute * attr) -> bool {
        return strcmp(attr->getName(), name) == 0;
    });
    return it != _attr.end() ? *it : nullptr;
}

void XmlNode::addAttribute(XmlAttribute *attribute)
{
    _attr.push_back(attribute);
}

bool XmlNode::hasAttribute(const char *name) const
{
    auto it = std::find_if(_attr.begin(), _attr.end(), [name](const XmlAttribute * attr) -> bool {
        return strcmp(attr->getName(), name) == 0;
    });
    return it != _attr.end();
}
