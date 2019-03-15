#include "Wire.h"

using namespace energy::core::metadata;
using namespace energy::model::network;

Wire::Wire(AbstractNetworkElement *parent) :
    AbstractNetworkElement{ parent }
{

}

const IMetadata &Wire::getMetadata() const
{
    return _metadata;
}

Wire::WireMetadata::WireMetadata() :
    _uuid(10, 00, 00, 00)
{

}

const energy::core::types::Uuid &Wire::WireMetadata::getTypeUid() const
{
    return _uuid;
}

const char *Wire::WireMetadata::getClassName() const
{
    return "Wire";
}

const char *Wire::WireMetadata::getFullClassName() const
{
    return "energy::model::network::Wire";
}
