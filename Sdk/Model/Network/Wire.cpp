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

Wire::Metadata::Metadata() :
    _uuid(10, 00, 00, 00)
{

}

const energy::core::types::Uuid &Wire::Metadata::getTypeUid() const
{
    return _uuid;
}

const char *Wire::Metadata::getClassName() const
{
    return "Wire";
}

const char *Wire::Metadata::getFullClassName() const
{
    return "energy::model::network::Wire";
}

MetaObject *Wire::Metadata::createInstance() const
{
    return new Wire();
}
