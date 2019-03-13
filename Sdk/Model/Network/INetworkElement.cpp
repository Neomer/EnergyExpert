#include "INetworkElement.h"

using namespace energy::model;
using namespace energy::model::network;
using namespace energy::core::types;

INetworkElement::INetworkElement(const INetworkElement *parent) :
    IIdentified(Uuid::Empty()),
    _parentElement{ parent }
{

}

bool INetworkElement::hasChildren() const
{
    return !_childElements.empty();
}
