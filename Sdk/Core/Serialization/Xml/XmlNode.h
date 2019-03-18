#ifndef XMLNODE_H
#define XMLNODE_H

#include <vector>

#include <Core/Serialization/Xml/XmlAttribute.h>

namespace energy { namespace core { namespace serialization { namespace xml {

/**
 * @brief Класс, представляющий каждый узел XML-объекта.
 */
class SDKSHARED_EXPORT XmlNode
{
public:
    /**
     * @brief Узел XML-дерева.
     * @param parent Указатель на родительский узел.
     */
    XmlNode(const XmlNode *parent = nullptr);
    /**
     * @brief Возвращает указатель на родительский узел.
     */
    const XmlNode *getParentNode() const;
    /**
     * @brief Имя тэга узла дерева
     */
    const char *getName() const;
    /**
     * @brief Установить имя тэга узла дерева
     * @param value Новое имя тэга
     */
    void setName(const char *value);
    /**
     * @brief Найти атрибут по имени.
     * @param name Имя атрибута.
     * @return Константный указатель на искомый атрибут, иначе nullptr, если атрибут указанным именем не найден.
     */
    const XmlAttribute *getAttribute(const char *name) const;
    /**
     * @brief Добавить атрибут к узлу
     * @param attribute
     */
    void addAttribute(XmlAttribute *attribute);
    /**
     * @brief Проверяет есть ли атрибут с указанным именем у элемента
     * @param name Наименование атрибута
     * @return true, если атрибут с указанным именем у элемента есть.
     */
    bool hasAttribute(const char *name) const;

private:
    const XmlNode *_parent;
    const char *_name;
    std::vector<XmlAttribute *> _attr;
};

} } } }

#endif // XMLNODE_H
