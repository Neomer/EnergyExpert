#include "AbstractNetworkElement.h"

using namespace energy::model;
using namespace energy::model::network;
using namespace energy::core::types;

AbstractNetworkElement::AbstractNetworkElement(AbstractNetworkElement *parent) :
    IIdentified(Uuid::Empty()),
    _parentElement{ parent }
{
    if (parent != nullptr) {
        parent->appendChild(this);
    }
}

AbstractNetworkElement::~AbstractNetworkElement()
{
    for(auto child : _childElements) {
        delete child;
    }
}

bool AbstractNetworkElement::hasChildren() const
{
    return !_childElements.empty();
}

const std::string &AbstractNetworkElement::getName() const
{
    return _name;
}

void AbstractNetworkElement::setName(const std::string value)
{
    _name = value;
}

void AbstractNetworkElement::setName(const char *value)
{
    _name = value;
}

void AbstractNetworkElement::appendChild(AbstractNetworkElement *child)
{
    child->_parentElement = this;
    _childElements.push_back(child);
}

const AbstractNetworkElement *AbstractNetworkElement::getParent() const
{
    return _parentElement;
}
