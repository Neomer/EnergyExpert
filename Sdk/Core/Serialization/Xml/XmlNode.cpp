#include <algorithm>
#include <string.h>

#include "XmlNode.h"

using namespace energy::core::serialization::xml;

XmlNode::XmlNode(const char *name, const XmlNode *parent) :
    _name{ name },
    _parent{ parent }
{

}

XmlNode::XmlNode(const char *name) :
    _name{ name },
    _parent{ nullptr }
{

}

XmlNode::XmlNode(const char *name, const char *value) :
    _name{ name },
    _parent{ nullptr },
    _value{ value }
{

}

XmlNode::~XmlNode()
{
    std::for_each(_children.begin(), _children.end(), [](XmlNode *item) {
        delete item;
    });

    std::for_each(_attr.begin(), _attr.end(), [](XmlAttribute *item) {
        delete item;
    });
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

std::vector<XmlAttribute *>::const_iterator XmlNode::getAttributesBeginIterator() const
{
    return _attr.begin();
}

std::vector<XmlAttribute *>::const_iterator XmlNode::getAttributesEndIterator() const
{
    _attr.end();
}

bool XmlNode::hasAnyAttributes() const
{
    return _attr.size();
}

bool XmlNode::hasAttribute(const char *name) const
{
    auto it = std::find_if(_attr.begin(), _attr.end(), [name](const XmlAttribute * attr) -> bool {
        return !strcmp(attr->getName(), name);
    });
    return it != _attr.end();
}

bool XmlNode::hasAnyChild() const
{
    return _children.size();
}

std::vector<XmlNode *> &XmlNode::getChildren()
{
    return _children;
}

std::vector<XmlNode *>::const_iterator XmlNode::getChildrenBeginIterator() const
{
    return _children.begin();
}

std::vector<XmlNode *>::const_iterator XmlNode::getChildrenEndIterator() const
{
    return _children.end();
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

const XmlNode *XmlNode::findFirstChild_const(const char *name, bool recursively) const
{
    for (auto it = _children.begin(); it != _children.end(); ++it) {
        if (!strcmp((*it)->getName(), name)) {
            return *it;
        }
        const XmlNode *result = (*it)->findFirstChild_const(name, recursively);
        if (result != nullptr) {
            return result;
        }
    }
    return nullptr;
}

XmlNode *XmlNode::findFirstChild(const char *name, bool recursively)
{
    for (auto it = _children.begin(); it != _children.end(); ++it) {
        if (!strcmp((*it)->getName(), name)) {
            return *it;
        }
        XmlNode *result = (*it)->findFirstChild(name, recursively);
        if (result != nullptr) {
            return result;
        }
    }
    return nullptr;
}

const std::string &XmlNode::getText_const() const
{
    return _value;
}

void XmlNode::setText(const std::string &data)
{
    _value = data;
}

void XmlNode::setText(const char *data)
{
    _value = data;
}

void XmlNode::setText(const energy::core::types::IStringable &stringable)
{
    stringable.toString(_value);
}

bool XmlNode::isEmpty() const
{
    return _children.size() == 0 && _value.empty();
}
