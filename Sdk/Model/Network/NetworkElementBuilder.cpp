#include "NetworkElementBuilder.h"

#include <Model/Network/Wire.h>
#include <Model/Network/TransformerSubstation.h>
#include <Model/Network/Thread.h>
#include <Model/Network/Bus.h>

using namespace energy::model::network;
using namespace energy::core::types;

NetworkElementBuilder::NetworkElementBuilder()
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

AbstractNetworkElement *NetworkElementBuilder::createElementByTypeUid(const Uuid &uid) const
{
    for (auto m : _metadataList) {
        if (m->getTypeUid().isEquals(uid)) {
            return static_cast<AbstractNetworkElement *>(m->createInstance());
        }
    }
    return nullptr;
}

const std::vector<energy::core::metadata::IMetadata *> NetworkElementBuilder::getElementTypeList() const
{
    return _metadataList;
}

NetworkElementBuilder &NetworkElementBuilder::getInstance()
{
    static NetworkElementBuilder i;
    return i;
}
