#ifndef IDATAREADER_H
#define IDATAREADER_H

#include <export.h>

#include "IDataStream.h"

namespace energy::core::data {

class SDKSHARED_EXPORT IDataReader
{
public:
    IDataReader(IDataStream &stream) : _stream{ stream } {}
    virtual ~IDataReader();

private:
    IDataStream &_stream;
};

}

#endif // #ifndef IDATAREADER_H
