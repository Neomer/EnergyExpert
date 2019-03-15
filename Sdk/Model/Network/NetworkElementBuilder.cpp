#include "NetworkElementBuilder.h"

#include <Model/Network/Wire.h>
#include <Model/Network/TransformerSubstation.h>
#include <Model/Network/Thread.h>
#include <Model/Network/Bus.h>

using namespace energy::core::metadata;
using namespace energy::model::network;
using namespace energy::core::types;

NetworkElementBuilder::NetworkElementBuilder() :
    BaseMetadataClassBuilder<AbstractNetworkElement>()
{
    _metadataList.push_back(new Wire::Metadata());
    _metadataList.push_back(new TransformerSubstation::Metadata());
    _metadataList.push_back(new Thread::Metadata());
    _metadataList.push_back(new Bus::Metadata());
}

NetworkElementBuilder::~NetworkElementBuilder()
{
    for (auto m : _metadataList) {
        delete m;
    }
}

NetworkElementBuilder &NetworkElementBuilder::getInstance()
{
    static NetworkElementBuilder i;
    return i;
}
