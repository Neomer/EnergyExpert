#include "NetworkElementBuilder.h"

#include <Sdk/Model/Network/Wire.h>
#include <Sdk/Model/Network/TransformerSubstation.h>
#include <Sdk/Model/Network/Thread.h>
#include <Sdk/Model/Network/Bus.h>

using namespace energy::core::metadata;
using namespace energy::model::network;
using namespace energy::core::types;

NetworkElementBuilder::NetworkElementBuilder() :
    BaseMetadataClassBuilder<AbstractNetworkElement>()
{
    safeLoad();
}

NetworkElementBuilder::~NetworkElementBuilder()
{

}

void NetworkElementBuilder::loadComponents()
{
    _metadataList.push_back(new Wire::Metadata());
    _metadataList.push_back(new TransformerSubstation::Metadata());
    _metadataList.push_back(new Thread::Metadata());
    _metadataList.push_back(new Bus::Metadata());
}

NetworkElementBuilder &NetworkElementBuilder::getInstance()
{
    static NetworkElementBuilder i;
    return i;
}
