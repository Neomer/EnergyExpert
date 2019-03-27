#include "SecurityUser.h"

using namespace energy::core::types;
using namespace energy::model::security;
using namespace energy::core::metadata;

SecurityUser::SecurityUser()
{

}

const IMetadata &SecurityUser::getMetadata() const
{
    return _metadata;
}

const char *SecurityUser::getDatabaseTable()
{
    return "SecurityUsers";
}

SecurityUser::Metadata::Metadata() :
    _typeUid(10, 00, 00, 04)
{

}

const Uuid &SecurityUser::Metadata::getTypeUid() const
{
    return _typeUid;
}

const char *SecurityUser::Metadata::getClassName() const
{
    return "SecurityUser";
}

const char *SecurityUser::Metadata::getFullClassName() const
{
    return "energy::model::security::SecurityUser";
}

MetaObject *SecurityUser::Metadata::createInstance() const
{
    return new SecurityUser();
}
