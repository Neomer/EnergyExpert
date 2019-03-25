#include <Sdk/os.h>

#ifdef _OS_WIN_

#include <winsock2.h>

#include <Sdk/Core/Exceptions/IOException.h>
#include "AbstractSocket.h"

using namespace energy::core::net;
using namespace energy::exceptions;

AbstractSocket::AbstractSocket()
{
}

AbstractSocket::AbstractSocket(const AbstractSocket &other) :
    _socketDescriptor{ other._socketDescriptor }
{

}

AbstractSocket::~AbstractSocket()
{

}

void AbstractSocket::setRemoteAddress(const Ip4Address &ipAddress)
{
    _remoteAddress = ipAddress;
}

void AbstractSocket::open(energy::core::data::IDataStream::Mode mode)
{

}

void AbstractSocket::close()
{

}

size_t AbstractSocket::write(const char *data, size_t size)
{

}

size_t AbstractSocket::write(const char *data)
{

}

size_t AbstractSocket::read(char *buffer, size_t max_size)
{

}

bool AbstractSocket::isOpen() const
{

}

#endif
