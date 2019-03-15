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

Thread::ThreadMetadata::ThreadMetadata() :
    _uuid(10, 00, 00, 02)
{

}

const energy::core::types::Uuid &Thread::ThreadMetadata::getTypeUid() const
{
    return _uuid;
}

const char *Thread::ThreadMetadata::getClassName() const
{
    return "Thread";
}

const char *Thread::ThreadMetadata::getFullClassName() const
{
    return "energy::core::metadata::Thread";
}
