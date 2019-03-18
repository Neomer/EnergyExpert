#ifndef INETWORKELEMENT_H
#define INETWORKELEMENT_H

#include <vector>

#include <Model/IIdentified.h>
#include <Core/Types/Uuid.h>
#include <Core/Types/IDrawable.h>
#include <Core/Metadata/MetaObject.h>

namespace energy { namespace model { namespace network {

/**
 * @brief Абстрактный класс, представляющий элемент электрической сети.
 * Все элементы, присутствующие в схеме электрической сети должны реализовать этот класс.
 */
class SDKSHARED_EXPORT AbstractNetworkElement :
        public energy::model::IIdentified<energy::core::types::Uuid>,
        public energy::core::metadata::MetaObject
{
public:
    /**
     * @brief Элемент сети.
     * @param uid Идентификатор элемента.
     * @param parent Родительский элемент электросети. Если значение отлично от nullptr, то данный экземпляр
     * добавляется в потомки класса родителя через метод AbstractNetworkElement::appendChild(AbstractNetworkElement *).
     */
    AbstractNetworkElement(const energy::core::types::Uuid &uid, AbstractNetworkElement *parent = nullptr);
    /**
     * @brief Элемент сети.
     * @param parent Родительский элемент электросети. Если значение отлично от nullptr, то данный экземпляр
     * добавляется в потомки класса родителя через метод AbstractNetworkElement::appendChild(AbstractNetworkElement *).
     */
    AbstractNetworkElement(AbstractNetworkElement *parent = nullptr);
    virtual ~AbstractNetworkElement() override;
    /**
     * @brief Проверка наличия дочерних элементов для узла электросети.
     * @return true, если у данного узла электросети есть дочерние элементы.
     */
    inline bool hasChildren() const;
    /**
     * @brief Наименование элемента электросети
     */
    inline const std::string &getName() const;
    /**
     * @brief Устанавливает наименование элемента электросети
     * @param value Новое имя элемента
     */
    void setName(const std::string value);
    /**
     * @brief Устанавливает наименование элемента электросети
     * @param value Новое имя элемента
     */
    void setName(const char *value);
    /**
     * @brief Добавляет потомка к данному узлу сети
     * @param child дочерний узел сети
     */
    void appendChild(AbstractNetworkElement *child);
    /**
     * @brief Возвращает родительский узел сети
     */
    const AbstractNetworkElement *getParent() const;

private:
    const AbstractNetworkElement *_parentElement;
    // NOTE: проверить скорость работы, возможно, что лучше будет использовать std:deque вместо вектора
    std::vector<AbstractNetworkElement *> _childElements;
    std::string _name;
};

} } }

#endif // INETWORKELEMENT_H
