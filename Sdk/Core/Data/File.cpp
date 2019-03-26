#include <stdexcept>
#include <cstring>

#include <Sdk/Core/Exceptions/NullPointerException.h>
#include <Sdk/Core/Data/Exceptions/DataStreamNotOpenException.h>
#include <Sdk/Core/Data/Exceptions/DataStreamAlreadyOpenException.h>

#include "File.h"

using namespace energy::exceptions;
using namespace energy::core::data;

File::File(const char *filename) :
    IDataStream(),
    _file{ nullptr },
    _filename{ filename }
{

}

File::~File()
{
    if (_file != nullptr) {
        std::fflush(_file);
        std::fclose(_file);
    }
}

void File::open(IDataStream::Mode mode)
{
    if (_filename == nullptr) {
        throw NullPointerException();
    }
    if (_file != nullptr) {
        throw DataStreamAlreadyOpenException();
    }
    const char *openMode;
    switch (mode)
    {
        case IDataStream::ReadOnly: openMode = "r"; break;
        case IDataStream::WriteOnly: openMode = "w"; break;
        case IDataStream::ReadWrite: openMode = "r+"; break;
        case IDataStream::Append: openMode = "a+"; break;
    }
    _file = std::fopen(_filename, openMode);
    if (_file == nullptr) {
        throw IOException();
    }
}

void File::close()
{
    if (_file == nullptr) {
        throw DataStreamNotOpenException();
    }
    std::fflush(_file);
    std::fclose(_file);
    _file = nullptr;
}

size_t File::write(const char *data, size_t size)
{
    if (_file == nullptr) {
        throw DataStreamNotOpenException();
    }
    return std::fwrite(data, 1, size, _file);
}

size_t File::write(const char *data)
{
    if (_file == nullptr) {
        throw DataStreamNotOpenException();
    }
    return std::fwrite(data, 1, std::strlen(data), _file);
}

size_t File::read(char *buffer, size_t max_size)
{
    if (_file == nullptr) {
        throw DataStreamNotOpenException();
    }
    return std::fread(buffer, 1, max_size, _file);
}

bool File::isOpen() const
{
    return _file != nullptr;
}
