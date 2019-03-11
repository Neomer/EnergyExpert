#ifndef ARRAYITERATOR_H
#define ARRAYITERATOR_H

#include "../../export.h"

#include "Iterator.h"

namespace energy { namespace core { namespace collections {

template<typename TElement>
class ArrayIterator : public Iterator<TElement>
{
public:
    ArrayIterator() : data_{nullptr} {}
    ArrayIterator(TElement *data) : data_{ data } {}
    ArrayIterator(const ArrayIterator<TElement> &other) : data_{ other.data_ } {}
    virtual ~ArrayIterator() { }

    ArrayIterator & operator =(const ArrayIterator<TElement> &other) { data_ = other.data_; }

    const TElement &get_const() const override { return *data_; }
    TElement &get() { return *data_; }

    const TElement *get_pointer_const() const override { return data_; }

    bool next() override { data_++; }
    bool prev() override { data_--; }

protected:
    TElement **get_pointer() override { return &data_; }

private:
    TElement *data_;
};

} } }

#endif // ARRAYITERATOR_H
