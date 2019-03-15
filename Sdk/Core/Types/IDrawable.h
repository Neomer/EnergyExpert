#ifndef IDRAWABLE_H
#define IDRAWABLE_H

namespace energy { namespace core { namespace types {

class IDrawable {
public:
    IDrawable() = default;
    virtual ~IDrawable() = default;

    virtual void Draw() = 0;
};

} } }

#endif // IDRAWABLE_H
