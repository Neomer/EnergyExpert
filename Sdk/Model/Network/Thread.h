#ifndef THREAD_H
#define THREAD_H

#include <Sdk/Model/Network/AbstractNetworkElement.h>

namespace energy { namespace model { namespace network {

/**
 * @brief Жила провода в электросети.
 */
class SDKSHARED_EXPORT Thread :
        public AbstractNetworkElement
{
public:
    class Metadata :
            public energy::core::metadata::IMetadata
    {
    public:
        Metadata();
        virtual ~Metadata() override = default;

        // IMetadata interface
    public:
        virtual const core::types::Uuid &getTypeUid() const override;
        virtual const char *getClassName() const override;
        virtual const char *getFullClassName() const override;
        virtual MetaObject *createInstance() const override;

    private:
        energy::core::types::Uuid _uuid;
    };

    Thread();
    virtual ~Thread() override = default;

    // MetaObject interface
public:
    virtual const core::metadata::IMetadata &getMetadata() const override;

private:
    Metadata _metadata;
};

} } }

#endif // THREAD_H
