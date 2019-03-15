#ifndef NETWORKELEMENTBUILDER_H
#define NETWORKELEMENTBUILDER_H

#include <vector>
#include <Core/Metadata/IMetadata.h>
#include <Model/Network/AbstractNetworkElement.h>

namespace energy { namespace model { namespace network {

/**
 * @brief Singleton класс для создания элементов сети, основываясь на их метаданных.
 */
class SDKSHARED_EXPORT NetworkElementBuilder
{
// Sigleton
public:
    static NetworkElementBuilder &getInstance();

private:
    NetworkElementBuilder();
    ~NetworkElementBuilder();

    NetworkElementBuilder(const NetworkElementBuilder &other) = delete;
    NetworkElementBuilder(NetworkElementBuilder &&other) = delete;
    NetworkElementBuilder &operator=(const NetworkElementBuilder &other) = delete;
    NetworkElementBuilder &operator=(NetworkElementBuilder &&other) = delete;

public:
    /**
     * @brief Создать элемент сети, основывясь на Uuid его типа.
     * @param uid Uuid типа элемента сети
     * @return Элемент сети, либо nullptr, если элемента с таким Uuid типа не зарегистрировано.
     */
    AbstractNetworkElement *createElementByTypeUid(const energy::core::types::Uuid &uid) const;
    const std::vector<energy::core::metadata::IMetadata *> getElementTypeList() const;


private:
    std::vector<energy::core::metadata::IMetadata *> _metadataList;


};

} } }

#endif // NETWORKELEMENTBUILDER_H
