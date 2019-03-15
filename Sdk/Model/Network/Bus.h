#ifndef BUS_H
#define BUS_H

#include <Model/Network/AbstractNetworkElement.h>

namespace energy { namespace model { namespace network {

/**
 * @brief Шина электросети.
 */
class SDKSHARED_EXPORT Bus :
        public AbstractNetworkElement
{
public:
    class BusMetadata :
            public energy::core::metadata::IMetadata
    {
    public:
        BusMetadata();
        virtual ~BusMetadata() override = default;

        // IMetadata interface
    public:
        virtual const core::types::Uuid &getTypeUid() const override;
        virtual const char *getClassName() const override;
        virtual const char *getFullClassName() const override;
        virtual MetaObject *createInstance() const override;

    private:
        energy::core::types::Uuid _uuid;
    };

    Bus();
    virtual ~Bus() override = default;

    // MetaObject interface
public:
    virtual const core::metadata::IMetadata &getMetadata() const override;

private:
    BusMetadata _metadata;
};

} } }

#endif // BUS_H
