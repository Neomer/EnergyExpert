#ifndef ITERATOR_H
#define ITERATOR_H

#include <export.h>

namespace energy { namespace core { namespace collections {

/**
 * Abstract class of Iterator pattern.
 */
template<typename TElement>
class SDKSHARED_EXPORT Iterator
{
public:
    Iterator() {}
    virtual ~Iterator() {}

    /**
     * @brief get_const returns element that pointed by iterator
     * @return
     */
    virtual const TElement &get_const() const = 0;
    /**
     * @brief get returns element that pointed by iterator
     * @return
     */
    virtual TElement &get() = 0;
    /**
     * @brief get_pointer_const returns pointer to element of collection
     * @return
     */
    virtual const TElement *get_pointer_const() const = 0;
    /**
     * @brief isEquals check equality of two iterators. By default compares to pointers, received by method Iterator::get_pointer_const.
     * @param other returns true if two iterators are equals.
     * @return
     */
    virtual bool isEquals(const Iterator<TElement> &other) const
    {
        return get_pointer_const() == other.get_pointer_const();
    }
    /**
     * @brief operator = changes iterator's pointer, received by method Iterator::get_pointer.
     * @param other
     * @return
     */
    virtual Iterator<TElement> &operator =(Iterator<TElement> &other)
    {
        auto p = get_pointer();
        auto p2 = other.get_pointer();

        *p = *p2;
        return *this;
    }
    /**
     * @brief next move pointer of iterator to a next element of collection
     * @return returns true, if this action is possibly
     */
    virtual bool next() = 0;
    /**
     * @brief prev next move pointer of iterator to a previous element of collection
     * @return returns true, if this action is possibly
     */
    virtual bool prev() = 0;

protected:
    /**
     * @brief get_pointer this method
     * @return
     */
    virtual TElement **get_pointer() = 0;
};

} } }

#endif // ITERATOR_H
