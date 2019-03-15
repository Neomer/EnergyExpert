#ifndef WIRE_H
#define WIRE_H

#include <Model/Network/AbstractNetworkElement.h>

namespace energy { namespace model { namespace network {

/**
 * @brief Линия электросети.
 * Представляет из себя физический провод между двумя излами.
 * Провод состоит из нескольких жил (как правило от 2х до 4х).
 */
class SDKSHARED_EXPORT Wire :
        public AbstractNetworkElement
{
public:
    /**
     * @brief Метаданные для линии электросети.
     */
    class WireMetadata : public energy::core::metadata::IMetadata
    {
    public:
        WireMetadata();
        virtual ~WireMetadata() override = default;

        // IMetadata interface
    public:
        virtual const core::types::Uuid &getTypeUid() const override;
        virtual const char *getClassName() const override;
        virtual const char *getFullClassName() const override;

    private:
        const energy::core::types::Uuid _uuid;
    };

    /**
     * @brief Создает линию электросети.
     * @param parent Родительский элемент электросети.
     */
    Wire(AbstractNetworkElement * parent = nullptr);
    virtual ~Wire() override = default;

    // MetaObject interface
public:
    virtual const core::metadata::IMetadata &getMetadata() const override;

private:
    WireMetadata _metadata;
};

} } }

#endif // WIRE_H
