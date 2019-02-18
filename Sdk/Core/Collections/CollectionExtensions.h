#ifndef COLLECTIONEXTENSIONS_H
#define COLLECTIONEXTENSIONS_H

#include <functional>

namespace energy { namespace core { namespace collections {

template<typename TElement, typename TColl>
void each(TColl &collection, std::function<void(const TElement &item)> action)
{
    for (auto it = collection.begin(); it != collection.end(); ++it)
    {
        action(*it);
    }
}

template<typename TElement, typename TIter>
void each(TIter begin, TIter end, std::function<void(const TElement &item)> action)
{
    for (auto it = begin; it != end; ++it)
    {
        action(*it);
    }
}

} } }

#endif // COLLECTIONEXTENSIONS_H
