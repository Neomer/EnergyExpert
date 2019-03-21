#include <cstring>

#include "BufferedWriteFile.h"

using namespace energy::core::data;

BufferedWriteFile::BufferedWriteFile(size_t cacheSize, const char *filename) :
    File(filename),
    _idx{ 0 },
    _cacheSize{ cacheSize }
{
    _buffer = new char[cacheSize];
}

BufferedWriteFile::~BufferedWriteFile()
{
    delete[] _buffer;
}

void BufferedWriteFile::flush()
{
    File::write(_buffer, _idx);
    _idx = 0;
}

size_t BufferedWriteFile::getCacheSize() const
{
    return _cacheSize;
}

size_t BufferedWriteFile::write(const char *data, size_t size)
{
    cache(data, size);
    return size;
}

size_t BufferedWriteFile::write(const char *data)
{
    size_t len = strlen(data);
    cache(data, len);
    return len;
}

void BufferedWriteFile::close()
{
    flush();
    File::close();
}

void BufferedWriteFile::cache(const char *data, size_t size)
{
    if (size > _cacheSize - _idx) {
        flush();
        File::write(data, size);
    } else {
        memcpy(_buffer, data, size);
        _idx += size;
    }
}
