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
    virtual void insert(std::shared_ptr<TIterator> &iterator, const TElement &value)
    {
        *(iterator.get()) = value;
    }
    /**
     * @brief each iterates for each element of collection
     * @param action method, that process each element of collection
     */
    virtual void each(std::function<void(const TElement &item)> action)
    {
        auto end = createEndIterator()->get();
        for (auto it = createBeginIterator()->get(); it != end; it.next())
        {
            action(it->get_const());
        }
    }
    /**
     * @brief where
     * @param selector
     * @return
     */
    virtual Collection<TElement, TIterator> &where(std::function<bool(const TElement &item)> selector)
    {
        Collection<TElement, TIterator> result;
        auto end = result.createEndIterator();
        each([=](const TElement &item)
        {
            if (selector(item))
            {
                result.insert(end, item);
            }
        });
        return result;
    }
};

} } }
#endif // COLLECTION_H
