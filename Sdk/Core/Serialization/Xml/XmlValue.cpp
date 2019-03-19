#include "XmlValue.h"

using namespace energy::core::serialization::xml;

XmlValue::XmlValue(const void *value) :
    _value{ value }
{

}

const std::string &XmlValue::asText() const
{
    return *(static_cast<const std::string *>(_value));
}
