#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include <Sdk/singleton.h>

namespace energy { namespace core { namespace types {

class IDrawable
{
    INTERFACE(IDrawable);

public:
    virtual void Draw() = 0;
};

} } }

#endif // IDRAWABLE_H
