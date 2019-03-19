#include <sstream>

#include <Core/Helpers/HtmlHelper.h>
#include "XmlTagNameDecorator.h"

using namespace energy::core::helpers;
using namespace energy::core::serialization::xml;

void XmlTagNameDecorator::decorate(std::stringstream &stream, const char *data) const
{
    std::string s = data;
    HtmlHelper::getInstance().encodeWithSpaces(s);
    stream << s;
}
