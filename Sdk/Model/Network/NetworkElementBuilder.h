#ifndef NETWORKELEMENTBUILDER_H
#define NETWORKELEMENTBUILDER_H

#include <Core/Metadata/BaseMetadataClassBuilder.h>
#include <Model/Network/AbstractNetworkElement.h>

namespace energy { namespace model { namespace network {

/**
 * @brief Singleton класс для создания элементов сети, основываясь на их метаданных.
 */
class SDKSHARED_EXPORT NetworkElementBuilder :
        public energy::core::metadata::BaseMetadataClassBuilder<AbstractNetworkElement>
{
// Sigleton
public:
    static NetworkElementBuilder &getInstance();

private:
    NetworkElementBuilder();
    virtual ~NetworkElementBuilder() override;

    NetworkElementBuilder(const NetworkElementBuilder &other) = delete;
    NetworkElementBuilder(NetworkElementBuilder &&other) = delete;
    NetworkElementBuilder &operator=(const NetworkElementBuilder &other) = delete;
    NetworkElementBuilder &operator=(NetworkElementBuilder &&other) = delete;

private:
    virtual void loadComponents() override;
};

} } }

#endif // NETWORKELEMENTBUILDER_H
