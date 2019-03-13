#ifndef INETWORKELEMENT_H
#define INETWORKELEMENT_H

#include <vector>

#include <Model/IIdentified.h>
#include <Core/Types/Uuid.h>

namespace energy { namespace model { namespace network {

/**
 * @brief INetworkElement интерфейс для элемента электрической сети.
 */
class INetworkElement : public energy::model::IIdentified<energy::core::types::Uuid>
{
public:
    /**
     * @brief INetworkElement конструктор элемента сети.
     * @param parent родительский элемент электросети.
     */
    INetworkElement(const INetworkElement *parent);
    /**
     * @brief hasChildren проверка наличия дочерних элементов для узла электросети.
     * @return true, если у данного узла электросети есть дочерние элементы.
     */
    inline bool hasChildren() const;

private:
    const INetworkElement *_parentElement;
    std::vector<INetworkElement *> _childElements;
};

} } }

#endif // INETWORKELEMENT_H
