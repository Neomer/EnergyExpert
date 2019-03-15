#include "TransformerSubstation.h"

using namespace energy::core::metadata;
using namespace energy::model::network;

TransformerSubstation::TransformerSubstation(AbstractNetworkElement *parent) :
    AbstractNetworkElement(parent)
{

}

const IMetadata &TransformerSubstation::getMetadata() const
{
    return _metadata;
}

TransformerSubstation::Metadata::Metadata() :
    _uuid(10, 00, 00, 01)
{

}

const energy::core::types::Uuid &TransformerSubstation::Metadata::getTypeUid() const
{
    return _uuid;
}

const char *TransformerSubstation::Metadata::getClassName() const
{
    return "TransformerSubstation";
}

const char *TransformerSubstation::Metadata::getFullClassName() const
{
    return "energy::model::network::TransformerSubstation";
}

MetaObject *TransformerSubstation::Metadata::createInstance() const
{
    return new TransformerSubstation();
}
