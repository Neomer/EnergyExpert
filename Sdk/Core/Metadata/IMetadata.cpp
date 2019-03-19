#include "IMetadata.h"
#include <functional>

using namespace energy::core::metadata;

IMetadata::IMetadata()
{

}

bool IMetadata::isSame(const IMetadata &other) const
{
    return getTypeUid().isEquals(other.getTypeUid());
}

void IMetadata::invoke(MetaObject *object, const char *methodName) const
{

}
