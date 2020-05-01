#ifndef CPPHTTP_SOCKET_H
#define CPPHTTP_SOCKET_H
#include <WS2tcpip.h>
#include <WinSock2.h>

#include <string>

#pragma comment(lib, "Ws2_32.lib")
#include <iostream>
namespace cpphttp
{
class Tcp
{
 public:
    struct RAIIAddrinfo
    {
        addrinfo* value;
        RAIIAddrinfo(addrinfo* value) : value(value)
        {
            // Do nothing
        }
        ~RAIIAddrinfo()
        {
            freeaddrinfo(value);
        }
    };
    Tcp();
    void init();
    void connect(const std::string& host, const int port);
    void send(const std::string& payload);
    void send(const char* payload, int size);
    RAIIAddrinfo dns_resolve(const std::string& host, const int port) const;

 private:
    int port;
    SOCKET socket = INVALID_SOCKET;
};
}  // namespace cpphttp
#endif  // CPPHTTP_SOCKET_H