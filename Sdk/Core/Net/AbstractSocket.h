#ifndef ABSTRACTSOCKET_H
#define ABSTRACTSOCKET_H

#include <Sdk/Core/Data/IDataStream.h>
#include <Sdk/Core/Net/Ip4Address.h>

namespace energy::core::net {

class SDKSHARED_EXPORT AbstractSocket : public energy::core::data::IDataStream
{
public:
    AbstractSocket();
    AbstractSocket(const AbstractSocket &other);
    virtual ~AbstractSocket() override;

    void setRemoteAddress(const energy::core::net::Ip4Address &ipAddress);

    // IDataStream interface
public:
    virtual void open(data::IDataStream::Mode mode) override;
    virtual void close() override;
    virtual size_t write(const char *data, size_t size) override;
    virtual size_t write(const char *data) override;
    virtual size_t read(char *buffer, size_t max_size) override;
    virtual bool isOpen() const override;

private:
    void *_socketDescriptor;
    energy::core::net::Ip4Address _remoteAddress;
};

}

#endif // ABSTRACTSOCKET_H
