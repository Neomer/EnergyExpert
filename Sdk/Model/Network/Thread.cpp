#include "Thread.h"

using namespace energy::model::network;
using namespace energy::core::metadata;

Thread::Thread()
{

}

const IMetadata &Thread::getMetadata() const
{
    return _metadata;
}

Thread::Metadata::Metadata() :
    _uuid(10, 00, 00, 02)
{

}

const energy::core::types::Uuid &Thread::Metadata::getTypeUid() const
{
    return _uuid;
}

const char *Thread::Metadata::getClassName() const
{
    return "Thread";
}

const char *Thread::Metadata::getFullClassName() const
{
    return "energy::core::metadata::Thread";
}

MetaObject *Thread::Metadata::createInstance() const
{
    return new Thread();
}
