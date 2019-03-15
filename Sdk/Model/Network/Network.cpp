#include "Network.h"

using namespace energy::model::network;

Network::Network()
{

}

const std::vector<AbstractNetworkElement *> &Network::getTopElements_const() const
{
    return _topElements;
}

std::vector<AbstractNetworkElement *> &Network::getTopElements()
{
    return _topElements;
}
