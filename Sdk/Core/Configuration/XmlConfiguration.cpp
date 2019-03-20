#include "XmlConfiguration.h"

#include <Core/Exceptions/NullPointerException.h>

using namespace energy::core::exceptions;
using namespace energy::core::configuration;
using namespace energy::core::serialization;
using namespace energy::core::serialization::xml;

XmlConfiguration::XmlConfiguration(ISerializer *serializer) :
    AbstractFileConfiguration (),
    _xmlSerializer{ serializer }
{

}

XmlConfiguration::~XmlConfiguration()
{

}

void XmlConfiguration::write(const char *key, int value)
{
    getNode(key)->setText(std::to_string(value));
}

void XmlConfiguration::write(const char *key, double value)
{
    getNode(key)->setText(std::to_string(value));
}

void XmlConfiguration::write(const char *key, std::string &value)
{
    getNode(key)->setText(value);
}

void XmlConfiguration::write(const char *key, const char *value)
{
    getNode(key)->setText(value);
}

void XmlConfiguration::write(const char *key, const energy::core::types::IStringable *value)
{
    getNode(key)->setText(value->toString());
}

int XmlConfiguration::readInt(const char *key) const
{
    return std::stoi(getNode_const(key)->getText_const());
}

double XmlConfiguration::readDouble(const char *key) const
{
    return std::stod(getNode_const(key)->getText_const());
}

std::string XmlConfiguration::readString(const char *key) const
{
    return getNode_const(key)->getText_const();
}

void XmlConfiguration::fileDataReady(const std::string &str)
{
    _xmlSerializer->deserialize(&_xmlObject, str);
}

XmlNode *XmlConfiguration::getNode(const char *key)
{
    if (key == nullptr) {
        throw NullPointerException();
    }
    auto node = _xmlObject.getRootNode().findFirstChild(key, true);
    if (node == nullptr) {
        node = new XmlNode(key);
        _xmlObject.getRootNode().getChildren().push_back(node);
    }
    if (node == nullptr) {
        throw NullPointerException();
    }
    return node;
}

const XmlNode *XmlConfiguration::getNode_const(const char *key) const
{
    if (key == nullptr) {
        throw NullPointerException();
    }
    auto node = _xmlObject.getRootNode_const().findFirstChild_const(key, true);
    if (node == nullptr) {
        throw IOException();
    }
    return node;
}
