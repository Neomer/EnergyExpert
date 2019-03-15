#ifndef TRANSFORMERSUBSTATION_H
#define TRANSFORMERSUBSTATION_H

#include <Model/Network/AbstractNetworkElement.h>

namespace energy { namespace model { namespace network {

/**
 * @brief Трансформаторная подстанция
 */
class SDKSHARED_EXPORT TransformerSubstation :
        public AbstractNetworkElement
{
public:
    /**
     * @brief Метаданные для класса трансформаторной подстанции.
     */
    class TransformerSubstationMetadata : public energy::core::metadata::IMetadata
    {
    public:
        TransformerSubstationMetadata();
        virtual ~TransformerSubstationMetadata() override = default;

        // IMetadata interface
    public:
        virtual const core::types::Uuid &getTypeUid() const override;
        virtual const char *getClassName() const override;
        virtual const char *getFullClassName() const override;
        virtual MetaObject *createInstance() const override;

    private:
        energy::core::types::Uuid _uuid;
    };

    TransformerSubstation(AbstractNetworkElement *parent = nullptr);
    virtual ~TransformerSubstation() override = default;

    // MetaObject interface
public:
    virtual const core::metadata::IMetadata &getMetadata() const override;

private:
    TransformerSubstationMetadata _metadata;
};

} } }

#endif // TRANSFORMERSUBSTATION_H
