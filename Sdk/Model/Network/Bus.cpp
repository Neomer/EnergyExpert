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

Bus::BusMetadata::BusMetadata() :
    _uuid(10, 00, 00, 03)
{

}

const energy::core::types::Uuid &Bus::BusMetadata::getTypeUid() const
{
    return _uuid;
}

const char *Bus::BusMetadata::getClassName() const
{
    return "Bus";
}

const char *Bus::BusMetadata::getFullClassName() const
{
    return "energy::model::network::Bus";
}
