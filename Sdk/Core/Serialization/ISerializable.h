#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

namespace energy { namespace core { namespace serialization {

class ISerializable
{
public:
    ISerializable() = default;
    virtual ~ISerializable() = default;
};

} } }

#endif // ISERIALIZABLE_H
