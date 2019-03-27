#include "AbstractEntity.h"

using namespace energy::model;
using namespace energy::core::types;

AbstractEntity::AbstractEntity() :
    IIdentified<Uuid>{ Uuid::Empty() }
{

}

AbstractEntity::AbstractEntity(const Uuid &id) :
    IIdentified<Uuid>{ id }
{

}

AbstractEntity::~AbstractEntity()
{

}
