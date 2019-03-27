#ifndef SECURITYUSER_H
#define SECURITYUSER_H

#include <Sdk/property.h>
#include <Sdk/Model/AbstractEntity.h>

namespace energy::model::security {

class SecurityUser : public AbstractEntity
{
public:
    class Metadata : public energy::core::metadata::IMetadata
    {
    public:
        Metadata();
        virtual ~Metadata() override = default;

        // IMetadata interface
    public:
        virtual const core::types::Uuid &getTypeUid() const override;
        virtual const char *getClassName() const override;
        virtual const char *getFullClassName() const override;
        virtual core::metadata::MetaObject *createInstance() const override;

    private:
        energy::core::types::Uuid _typeUid;
    };

    SecurityUser();
    virtual ~SecurityUser() override = default;

    PR(const char*, Username)

    // MetaObject interface
public:
    virtual const core::metadata::IMetadata &getMetadata() const override;

    // AbstractEntity interface
public:
    virtual const char *getDatabaseTable() override;

private:
    Metadata _metadata;
};

}


#endif // SECURITYUSER_H
