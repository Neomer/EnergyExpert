#include "XmlAttribute.h"

using namespace energy::core::serialization::xml;

XmlAttribute::XmlAttribute()
{

}

XmlAttribute::XmlAttribute(const char *name, const char *value) :
    _name{ name },
    _value{ value }
{

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
