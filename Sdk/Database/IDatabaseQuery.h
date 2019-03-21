#ifndef IDATABASEQUERY_H
#define IDATABASEQUERY_H

#include <cinttypes>
#include <memory>

#include <Sdk/Database/IDatabaseValue.h>

namespace energy { namespace database {

class IDatabaseQuery
{
public:
    IDatabaseQuery() = default;
    virtual ~IDatabaseQuery() = default;

    virtual size_t getNumRows() const = 0;
    virtual size_t getNumColumns() const = 0;

    virtual const char *getColumn(size_t index) const = 0;
    virtual size_t getColumnIndex(const char *name) const = 0;

    virtual bool isEmpty() const = 0;
    virtual bool next() = 0;

    virtual std::shared_ptr<IDatabaseValue> getValue(size_t column) const = 0;
};

} }

#endif // IDATABASEQUERY_H
