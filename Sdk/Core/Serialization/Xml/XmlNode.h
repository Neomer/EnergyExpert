#ifndef XMLNODE_H
#define XMLNODE_H

#include <vector>

#include <Core/Serialization/Xml/XmlAttribute.h>
#include <Core/Serialization/Xml/XmlValue.h>
#include <Core/Serialization/Xml/IXmlSerializable.h>
#include <Core/Types/IStringable.h>

namespace energy { namespace core { namespace serialization { namespace xml {

/**
 * @brief Класс, представляющий каждый узел XML-объекта.
 * Элемент XML-документа представляет из себя объект ограниченный тэгами <{имя тэга} [{имя атрибута}={значение атрибута} ...]>{данные}</{имя тэга}>.<br />
 * Имя тэга - обязательное свойство и задается через конструктор. Получить его можно с помощью метода XmlNode::getName(), а изменить
 * с помощью метода XmlNode::setName(const char *).<br />
 * Данными для элемента могут служить либо вложенные элементы, либо текст. При этом, если для узла одновременно установлен и текст, и имеются
 * дочерние узлы, то текст отображен не будет.<br />
 * Установить текст можно с помощью метода XmlNode::setText, а добавить/изменить дочерние элементы через получения указателя на
 * вектор элементов с помощью метода XmlNode::getChildren(). Итерацию по потомкам можно производить через доступ к итераторам с помощью
 * XmlNode::getChildrenBeginIterator() и XmlNode::getChildrenEndIterator().<br />
 *
 * Например, код используемый в XmlSerializerImpl.
 * @code
 *   stream << "<" << node->getName() << ">";
 *   if (node->hasChildren()) {
 *       std::for_each(node->getChildrenBeginIterator(), node->getChildrenEndIterator(), [this, &stream](const XmlNode *item) {
 *          stream << serialize(item);
 *       });
 *   } else {
 *       stream << node->getText_const();
 *   }
 *   stream << "</" << node->getName() << ">";
 *
 * @endcode
 */
class SDKSHARED_EXPORT XmlNode : public IXmlSerializable
{
public:
    /**
     * @brief Узел XML-дерева.
     * @param parent Указатель на родительский узел.
     */
    XmlNode(const char *name, const XmlNode *parent);
    /**
     * @brief Узел XML-дерева.
     * @param name Наименование тэга
     */
    XmlNode(const char *name);
    /**
     * @brief Узел XML-дерева.
     * @param name Наименование тэга
     * @param value Текстовое значение
     */
    XmlNode(const char *name, const char *value);
    ~XmlNode();
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
     * @brief Итератор на начало списка атрибутов
     */
    std::vector<XmlAttribute *>::const_iterator getAttributesBeginIterator() const;
    /**
     * @brief Итератор на конец списка атрибутов
     */
    std::vector<XmlAttribute *>::const_iterator getAttributesEndIterator() const;
    /**
     * @brief Проверяет наличие у тэга хотя бы одного атрибута
     * @return
     */
    bool hasAnyAttributes() const;
    /**
     * @brief Проверяет есть ли атрибут с указанным именем у элемента
     * @param name Наименование атрибута
     * @return true, если атрибут с указанным именем у элемента есть.
     */
    bool hasAttribute(const char *name) const;
    /**
     * @brief Проверяет есть ли у элемента дочерние элементы
     */
    bool hasAnyChild() const;
    /**
     * @brief Возвращает список дочерних элементов
     */
    std::vector<XmlNode *> &getChildren();
    /**
     * @brief Итератор на начало списка дочерних элементов
     */
    std::vector<XmlNode *>::const_iterator getChildrenBeginIterator() const;
    /**
     * @brief Итератор на конец списка дочерних элементов
     */
    std::vector<XmlNode *>::const_iterator getChildrenEndIterator() const;
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
    /**
     * @brief Возвращает значение элемента XML-документа.
     * Вначале необходимо проверить есть ли у элемента дочерние элементы с помощью метода XmlNode::hasChildren().
     * Если у элемента есть дочерние элементы, то доступ к ним необходимо получить с помощью метода XmlNode::getChildren()
     * @return
     */
    const std::string &getText_const() const;
    /**
     * @brief Устанавливает текстовые данные для элемента. Не будет использоваться при сериализации, если у элемента есть дочерние узлы.
     * @param data Строка
     */
    void setText(const std::string &data);
    /**
     * @brief Устанавливает текстовые данные для элемента. Не будет использоваться при сериализации, если у элемента есть дочерние узлы.
     * @param data Строка
     */
    void setText(const char *data);
    /**
     * @brief Устанавливает текстовые данные для элемента. Не будет использоваться при сериализации, если у элемента есть дочерние узлы.
     * @param stringable Класс, реализующий интерфейс energy::core::types::IStringable
     */
    void setText(const energy::core::types::IStringable &stringable);
    /**
     * @brief Проверяет пустой ли элемент
     * @return true, если у элемента нет ни значения, ни дочерних элементов
     */
    bool isEmpty() const;

private:
    const char *_name;
    const XmlNode *_parent;
    std::vector<XmlAttribute *> _attr;
    std::vector<XmlNode *> _children;
    std::string _value;
};

} } } }

#endif // XMLNODE_H
