#include "HtmlHelper.h"

using namespace energy::core::helpers;

HtmlHelper::HtmlHelper()
{

}

void HtmlHelper::encode(std::string &str)
{
    std::string buffer;
    buffer.reserve(str.size());
    for(size_t pos = 0; pos != str.size(); ++pos) {
        switch(str[pos]) {
            case '&':  buffer.append("&amp;");       break;
            case '\"': buffer.append("&quot;");      break;
            case '\'': buffer.append("&apos;");      break;
            case '<':  buffer.append("&lt;");        break;
            case '>':  buffer.append("&gt;");        break;
            default:   buffer.append(&str[pos], 1); break;
        }
    }
    str.swap(buffer);
}

void HtmlHelper::encodeWithSpaces(std::string &str)
{
    std::string buffer;
    buffer.reserve(str.size());
    for(size_t pos = 0; pos != str.size(); ++pos) {
        switch(str[pos]) {
            case '&':  buffer.append("&amp;");       break;
            case '\"': buffer.append("&quot;");      break;
            case '\'': buffer.append("&apos;");      break;
            case '<':  buffer.append("&lt;");        break;
            case '>':  buffer.append("&gt;");        break;
            case ' ':  buffer.append("&#032;");      break;
            default:   buffer.append(&str[pos], 1); break;
        }
    }
    str.swap(buffer);
}

