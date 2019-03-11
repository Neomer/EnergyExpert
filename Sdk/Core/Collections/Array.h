#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <memory>

#include "../../export.h"
#include "ArrayIterator.h"
#include "Collection.h"

namespace energy { namespace core { namespace collections {

/**
 * Array is const-size collection.
 */
template<typename TElement>
class Array : public Collection<TElement, ArrayIterator<TElement>>
{
public:
    Array(size_t size) :
        Collection<TElement, ArrayIterator<TElement>>()
    {
        begin_ = new TElement[size];
        end_ = begin_ + size;
        size_ = size;

        begin_iter_ = ArrayIterator<TElement>(begin_);
        end_iter_ = ArrayIterator<TElement>(end_);
    }

    Array(std::initializer_list<TElement> list) :
        Collection<TElement, ArrayIterator<TElement> > (list)
    {

    }

    void insert(size_t index, const TElement &value)
    {
        *(begin_ + index) = value;
    }

    size_t size() override
    {
        return size_;
    }

    ArrayIterator<TElement> &begin() override
    {
        return begin_iter_;
    }

    ArrayIterator<TElement> &end() override
    {
        return end_iter_;
    }

    const ArrayIterator<TElement> &begin_const() const override
    {
        return  begin_iter_;
    }

    const ArrayIterator<TElement> &end_const() const override
    {
        return end_iter_;
    }

    /**
     * @brief fill set same value to whole array
     * @param value to be satted
     */
    void fill(const TElement &value)
    {
    }

    /**
     * @brief at returns element by index
     * @param index number of element
     * @return
     */
    const TElement &at(size_t index)
    {
        return *(begin_ + index);
    }

private:
    TElement *begin_, *end_;
    ArrayIterator<TElement> begin_iter_, end_iter_;
    size_t size_;
};

} } }


#endif // ARRAY_H
