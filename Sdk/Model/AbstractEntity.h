#ifndef ABSTRACTENTITY_H
#define ABSTRACTENTITY_H

#include <Sdk/Model/IIdentified.h>
#include <Sdk/Core/Types/Uuid.h>
#include <Sdk/Core/Metadata/MetaObject.h>

namespace energy::model {

class AbstractEntity :
        public IIdentified<energy::core::types::Uuid>,
        public energy::core::metadata::MetaObject
{
public:
    AbstractEntity();
    AbstractEntity(const energy::core::types::Uuid &id);
    virtual ~AbstractEntity() override;

    virtual const char *getDatabaseTable() = 0;
};

}


#endif // ABSTRACTENTITY_H
