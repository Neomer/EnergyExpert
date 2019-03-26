#ifndef JSONARRAY_H
#define JSONARRAY_H

#include <Sdk/export.h>
#include <Sdk/Core/Serialization/Json/JsonValue.h>

namespace energy { namespace core { namespace serialization { namespace json {

class SDKSHARED_EXPORT JsonArray final : public JsonValue
{
public:
    JsonArray();
    ~JsonArray();
};

} } } }

#endif // JSONARRAY_H
