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
    /**
     * @brief Найти элементы с заданным именем тэга
     * @param name Имя тэга
     * @return Вектор со списком указателей на элементы.
     */
    std::vector<const XmlNode *> findChildren(const char *name) const;
    /**
     * @brief Найти первый элемент с указанным именем тэга.
     * @param name Наименование тэга элемента
     * @param recursively Проверять с учетом вложенных элементов
     * @return Константный указатель на элемент, либо nullptr, если элемент с таким именем не найден.
     */
    const XmlNode *findFirstChild(const char *name, bool recursively) const;

private:
    const XmlNode *_parent;
    const char *_name;
    std::vector<XmlAttribute *> _attr;
    std::vector<XmlNode *> _children;
};

} } } }

#endif // XMLNODE_H
