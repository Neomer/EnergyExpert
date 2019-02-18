#ifndef COLLECTION_H
#define COLLECTION_H

#include <memory>
#include <functional>
#include <algorithm>

#include "../../export.h"
#include "Iterator.h"

namespace energy { namespace core { namespace collections {

/**
 * Abstract class of default Collection. Contains base functionality for element access.
 */
template<typename TElement, typename TIterator>
class SDKSHARED_EXPORT Collection
{
public:
    /**
     * @brief Collection creates new instace of Collection
     */
    Collection() {}
    virtual ~Collection() {}

    /**
     * @brief createBeginIterator creates a new iterator, pointed to first element
     * @return
     */
    virtual std::shared_ptr<TIterator> createBeginIterator() = 0;
    /**
     * @brief createEndIterator creates a new iterator, pointed to a last element
     * @return
     */
    virtual std::shared_ptr<TIterator> createEndIterator() = 0;
    /**
     * @brief each iterates for each element of collection
     * @param predicate method, that process each element of collection
     */
    virtual void each(std::function<void(const TElement &item)> predicate)
    {
        auto end = createEndIterator()->get();
        for (auto it = createBeginIterator()->get(); it != end; it.next())
        {
            predicate(it->get_const());
        }
    }
    /**
     * @brief where
     * @param predicate
     * @return
     */
    virtual Collection<TElement, TIterator> &where(std::function<bool(const TElement &item)> predicate)
    {
        Collection<TElement, TIterator> result;
        each([=](const TElement &item)
        {
            if (predicate(item))
            {

            }
        });
        return result;
    }
};

} } }
#endif // COLLECTION_H
