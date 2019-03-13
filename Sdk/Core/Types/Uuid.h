#ifndef UUID_H
#define UUID_H

#include <string>
#include <inttypes.h>

namespace energy { namespace core { namespace types {

class Uuid
{
public:
    Uuid(const std::string &string);
    Uuid(const char *data);
    Uuid(const Uuid &other);

    static Uuid Empty();

    void clear();

    constexpr size_t size() const;

    inline bool isEquals(const Uuid &other) const;

    bool operator==(const Uuid &other) const;
    bool operator!=(const Uuid &other) const;

    bool operator>(const Uuid &other) const;
    bool operator>=(const Uuid &other) const;

    bool operator<(const Uuid &other) const;
    bool operator<=(const Uuid &other) const;

private:
    Uuid();

    uint32_t _dw[4];
};

} } }

#endif // UUID_H
