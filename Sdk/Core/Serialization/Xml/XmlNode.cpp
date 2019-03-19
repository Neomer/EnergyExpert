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
        return !strcmp(attr->getName(), name);
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
        return !strcmp(attr->getName(), name);
    });
    return it != _attr.end();
}

std::vector<const XmlNode *> XmlNode::findChildren(const char *name) const
{
    std::vector<const XmlNode *> ret;
    for (auto it = _children.begin(); it != _children.end(); ++it) {
        if (!strcmp((*it)->getName(), name)) {
            ret.push_back(*it);
        }
    }
    return ret;
}

const XmlNode *XmlNode::findFirstChild(const char *name, bool recursively) const
{
    for (auto it = _children.begin(); it != _children.end(); ++it) {
        if (!strcmp((*it)->getName(), name)) {
            return *it;
        }
        const XmlNode *result = (*it)->findFirstChild(name, recursively);
        if (result != nullptr) {
            return result;
        }
    }
    return nullptr;
}
