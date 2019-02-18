#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <memory>

#include "../../export.h"
#include "ArrayIterator.h"
#include "Collection.h"

namespace energy { namespace core { namespace collections {

template<typename TElement>
class SDKSHARED_EXPORT Array : public Collection<TElement, ArrayIterator<TElement>>
{
public:
    Array() :
        Collection<TElement, ArrayIterator<TElement>>()
    {
        begin_ = end_ = nullptr;
    }

    std::shared_ptr<ArrayIterator<TElement>> createBeginIterator() override
    {
        return std::shared_ptr<ArrayIterator<TElement>>(new ArrayIterator<TElement>(begin_));
    }

    std::shared_ptr<ArrayIterator<TElement>> createEndIterator() override
    {
        return std::shared_ptr<ArrayIterator<TElement>>(new ArrayIterator<TElement>(end_));
    }

private:
    TElement *begin_, *end_;
};

} } }


#endif // ARRAY_H
