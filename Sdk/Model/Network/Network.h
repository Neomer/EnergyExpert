#ifndef NETWORK_H
#define NETWORK_H

#include <vector>

#include <Sdk/Model/Network/AbstractNetworkElement.h>

namespace energy { namespace model { namespace network {

/**
 * @brief Электрическая сеть.
 */
class SDKSHARED_EXPORT Network
{
public:
    Network();

    /**
     * @brief Получить список элементов верхнего уровня.
     * @return Константный указатель на список элементов верхнего уровня.
     */
    const std::vector<AbstractNetworkElement *> &getTopElements_const() const;
    /**
     * @brief Получить список элементов верхнего уровня.
     * @return Указатель на список элементов верхнего уровня.
     */
    std::vector<AbstractNetworkElement *> &getTopElements();

private:
    std::vector<AbstractNetworkElement *> _topElements;
};

} } }


#endif // NETWORK_H
