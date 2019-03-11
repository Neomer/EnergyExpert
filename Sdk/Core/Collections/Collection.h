#ifndef COLLECTION_H
#define COLLECTION_H

#include <memory>
#include <functional>
#include <algorithm>
#include <cstddef>

#include "../../export.h"
#include "Iterator.h"

namespace energy { namespace core { namespace collections {

/**
 * Abstract class of default Collection. Contains base functionality for element access.
 */
template<typename TElement, typename TIterator>
class Collection
{
public:
    /**
     * @brief Collection creates new instace of Collection
     */
    Collection() {}

    Collection(std::initializer_list<TElement> items)
    {
        for (auto it = items.begin(); it != items.end(); ++it)
        {
            insert(it, *it);
        }
    }

    virtual ~Collection() {}
    /**
     * @brief begin creates a new iterator, pointed to first element
     * @return
     */
    virtual TIterator &begin() = 0;
    /**
     * @brief end creates a new iterator, pointed to a last element
     * @return
     */
    virtual TIterator &end() = 0;

    /**
     * @brief begin_const creates a new iterator, pointed to a last element
     * @return
     */
    virtual const TIterator &begin_const() const = 0;
    /**
     * @brief end_const creates a new iterator, pointed to a last element
     * @return constant reference to the last element's iterator
     */
    virtual const TIterator &end_const() const = 0;

    virtual void insert(std::shared_ptr<TIterator> &iterator, const TElement &value)
    {

    }
    /**
     * @brief each iterates for each element of collection
     * @param action method, that process each element of collection
     */
    virtual void each(std::function<void(const TElement &item)> action)
    {
        for (auto it = begin(); !it.isEquals(end()); it.next())
        {
            action(it.get_const());
        }
    }
    /**
     * @brief where
     * @param selector
     * @return
     */
    virtual Collection<TElement, TIterator> &where(std::function<bool(const TElement &item)> selector)
    {
        /*
        Collection<TElement, TIterator> result;
        each([=](const TElement &item) {
            if (selector(item))
            {

            }
        });
        return result;
        */
    }

    /**
     * @brief size returns size of collection.
     * @warning do not recommended in statements like
     * \code
     * if (some_collection.size() > 0) { ... }
     * \endcode
     * or
     * \code
     * bool isEmpty = some_collection.size() == 0;
     * \endcode
     * because this method takes linear time O(n). For emptiness detection you *SHOULD* use Collection::any(), that takes constant time O(1).
     * @return
     */
    virtual size_t size()
    {
        size_t result = 0;
        for (auto it = begin(); !it.isEquals(end()); it.next(), result++);
        return result;
    }

    /**
     * @brief any returns true, if any element stored in the collection
     * @return
     */
    virtual bool any() const
    {
        return begin_const().isEquals(end_const());
    }
};

} } }
#endif // COLLECTION_H

