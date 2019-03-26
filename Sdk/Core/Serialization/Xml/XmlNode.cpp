#include <algorithm>
#include <string.h>

#include "XmlNode.h"

using namespace energy::core::serialization::xml;

XmlNode::XmlNode(const char *name, XmlNode *parent) :
    _name{ name },
    _parent{ parent },
    _enableEvents{ true }
{

}

XmlNode::XmlNode(const char *name) :
    _name{ name },
    _parent{ nullptr },
    _enableEvents{ true }
{

}

XmlNode::XmlNode(const char *name, const char *value) :
    _name{ name },
    _parent{ nullptr },
    _value{ value },
    _enableEvents{ true }
{

}

XmlNode::~XmlNode()
{
    if (_parent != nullptr) {
        _parent->onChildDestroying(this);
    }
    clearAttributes();
    clearChildren();
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

void XmlNode::appendAttribute(XmlAttribute *attribute)
{
    attribute->setDestroyListener(this);
    _attr.push_back(attribute);
}

std::vector<XmlAttribute *>::const_iterator XmlNode::getAttributesBeginIterator() const
{
    return _attr.begin();
}

std::vector<XmlAttribute *>::const_iterator XmlNode::getAttributesEndIterator() const
{
    return _attr.end();
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

const std::vector<XmlNode *> &XmlNode::getChildren() const
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

XmlNode *XmlNode::appendChild(XmlNode *node)
{
    node->_parent = this;
    _children.push_back(node);
    return node;
}

void XmlNode::clearAttributes()
{
    disableEvents();
    while (_attr.begin() != _attr.end()) {
        delete _attr[0];
    };
    enableEvents();
}

void XmlNode::clearChildren()
{
    disableEvents();
    while (_children.begin() != _children.end()) {
        delete _children[0];
    };
    enableEvents();
}

void XmlNode::onChildDestroying(const XmlNode *node)
{
    if (!_enableEvents) {
        _children.erase(std::remove(_children.begin(), _children.end(), node), _children.end());
    }
}

void XmlNode::enableEvents()
{
    _enableEvents = true;
}

void XmlNode::disableEvents()
{
    _enableEvents = false;
}

void XmlNode::onXmlAttributeDestroying(const XmlAttribute *xmlAttribute)
{
    if (!_enableEvents) {
        _attr.erase(std::remove(_attr.begin(), _attr.end(), xmlAttribute), _attr.end());
    }
}
