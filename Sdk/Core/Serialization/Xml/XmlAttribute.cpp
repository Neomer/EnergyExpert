#include "XmlAttribute.h"

#include <Sdk/Core/Serialization/Xml/XmlNode.h>

using namespace energy::core::serialization::xml;

XmlAttribute::XmlAttribute() :
    _destroyListener{ nullptr }
{

}

XmlAttribute::XmlAttribute(const char *name, const char *value) :
    _name{ name },
    _value{ value },
    _destroyListener{ nullptr }
{

}

XmlAttribute::~XmlAttribute()
{
    if (_destroyListener != nullptr) {
        _destroyListener->onXmlAttributeDestroying(this);
    }
}

const char *XmlAttribute::getName() const
{
    return _name;
}

void XmlAttribute::setName(const char *value)
{
    _name = value;
}

const char *XmlAttribute::getTextValue() const
{
    return _value;
}

void XmlAttribute::setValue(const char *value)
{
    _value = value;
}

void XmlAttribute::setDestroyListener(IXmlAttributeDestroyingListener *destroyListener)
{
    _destroyListener = destroyListener;
}
