#include "IMetadata.h"

using namespace energy::core::metadata;

IMetadata::IMetadata()
{

}

bool IMetadata::isSame(const IMetadata &other) const
{
    return getTypeUid().isEquals(other.getTypeUid());
}
