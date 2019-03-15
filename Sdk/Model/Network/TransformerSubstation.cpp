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

TransformerSubstation::TransformerSubstationMetadata::TransformerSubstationMetadata() :
    _uuid(10, 00, 00, 01)
{

}

const energy::core::types::Uuid &TransformerSubstation::TransformerSubstationMetadata::getTypeUid() const
{
    return _uuid;
}

const char *TransformerSubstation::TransformerSubstationMetadata::getClassName() const
{
    return "TransformerSubstation";
}

const char *TransformerSubstation::TransformerSubstationMetadata::getFullClassName() const
{
    return "energy::model::network::TransformerSubstation";
}

MetaObject *TransformerSubstation::TransformerSubstationMetadata::createInstance() const
{
    return new TransformerSubstation();
}
