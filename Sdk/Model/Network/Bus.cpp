#include "Bus.h"

using namespace energy::model::network;
using namespace energy::core::metadata;

Bus::Bus()
{

}

const IMetadata &Bus::getMetadata() const
{
    return _metadata;
}

Bus::Metadata::Metadata() :
    _uuid(10, 00, 00, 03)
{

}

const energy::core::types::Uuid &Bus::Metadata::getTypeUid() const
{
    return _uuid;
}

const char *Bus::Metadata::getClassName() const
{
    return "Bus";
}

const char *Bus::Metadata::getFullClassName() const
{
    return "energy::model::network::Bus";
}

MetaObject *Bus::Metadata::createInstance() const
{
    return new Bus();
}
