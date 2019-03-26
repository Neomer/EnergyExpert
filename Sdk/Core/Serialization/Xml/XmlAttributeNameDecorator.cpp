#include <sstream>

#include <Sdk/Core/Helpers/HtmlHelper.h>
#include "XmlAttributeNameDecorator.h"

using namespace energy::core::helpers;
using namespace energy::core::serialization::xml;

void XmlAttributeNameDecorator::decorate(std::stringstream &stream, const char *data) const
{
    std::string s = data;
    HtmlHelper::getInstance().encodeWithSpaces(s);
    stream << s;
}
