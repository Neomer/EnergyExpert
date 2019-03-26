#ifndef HTMLHELPER_H
#define HTMLHELPER_H

#include <Sdk/export.h>
#include <Sdk/singleton.h>
#include <string>

namespace energy { namespace core { namespace helpers {

class SDKSHARED_EXPORT HtmlHelper
{
    SINGLETON(HtmlHelper)

private:
    HtmlHelper();
    ~HtmlHelper() = default;


public:
    /**
     * @brief Экранировать все системные символы
     * @param str Строка, которую нужно экранировать
     */
    void encode(std::string &str);
    /**
     * @brief Экранировать все системные символы, включая пробелы. Используется для экранирования имен тэгов.
     * @param str Строка, которую нужно экранировать
     */
    void encodeWithSpaces(std::string &str);
};

} } }

#endif // HTMLHELPER_H
