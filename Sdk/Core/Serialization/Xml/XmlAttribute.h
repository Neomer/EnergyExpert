#ifndef XMLATTRIBUTE_H
#define XMLATTRIBUTE_H

#include <export.h>

namespace energy { namespace core { namespace serialization { namespace xml {

/**
 * @brief Атрибут узла XML документа.
 */
class SDKSHARED_EXPORT XmlAttribute
{
public:
    explicit XmlAttribute();
    explicit XmlAttribute(const char *name, const char *value);

    /**
     * @brief Имя атрибута
     */
    const char *getName() const;
    /**
     * @brief setName Установить имя атрибута
     * @param value Новое имя атрибута
     */
    void setName(const char *value);
    /**
     * @brief Значение атрибута в виде строки
     */
    const char *getTextValue() const;
    /**
     * @brief setValue Установить новое значение для атрибута
     * @param value Новое значение атрибута
     */
    void setValue(const char *value);

private:
    const char *_name;
    const char *_value;
};

} } } }

#endif // XMLATTRIBUTE_H
