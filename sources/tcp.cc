#include <array>
#include <cassert>
#include <charconv>
#include <stdexcept>
#include <tcp.hpp>

using namespace cpphttp;

Tcp::Tcp()
{
    WSADATA wsa_data;
    WSAStartup(MAKEWORD(2, 2), &wsa_data);
}

void Tcp::init()
{
    if (socket != INVALID_SOCKET)
    {
        // TODO: already connected
    }
    socket = ::socket(PF_INET, SOCK_STREAM, 0);
}

void Tcp::connect(const std::string& host, const int port)
{
    if (socket != INVALID_SOCKET)
    {
        throw std::runtime_error("already connected");
    }

    // TODO: implement connect
    auto info = dns_resolve(host, port);
    assert(info.value);

    for (auto ai = info.value; ai; ai = ai->ai_next)
    {
        socket = ::socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
        if (socket == INVALID_SOCKET)
        {
            continue;
        }
        if (::connect(socket, ai->ai_addr, ai->ai_addrlen) == SOCKET_ERROR)
        {
            closesocket(socket);
            continue;
        }
        return;
    }
}

Tcp::RAIIAddrinfo Tcp::dns_resolve(const std::string& host,
                                   const int port) const
{
    std::array<char, 6> sPort {};
    auto [p, ec] =
        std::to_chars(sPort.data(), sPort.data() + sPort.size(), port);
    assert(ec == std::errc());

    static addrinfo hints = []() {
        addrinfo hints;
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;
        return hints;
    }();
    addrinfo* result {};

    auto status = getaddrinfo(host.c_str(), sPort.data(), &hints, &result);
    // TODO: exception handling when status is not 0

    return { result };
}

void Tcp::send(const std::string& payload)
{
    send(payload.c_str(), payload.size());
}

void Tcp::send(const char* payload, int size)
{
    if (socket == INVALID_SOCKET)
    {
        throw std::runtime_error("invalid socket");
    }
    while (size > 0)
    {
        auto len = ::send(socket, payload, size, 0);
        if (len < 0)
        {
            // TODO: exception handling when len < 0
        }
        size -= len;
        payload += len;
    }
}

std::string Tcp::recv()
{
    std::array<char, buffer_size> buf;
    std::string result;
    int len;
    while ((len = ::recv(socket, buf.data(), buf.size(), 0)) > 0)
    {
        result.append(buf.data(), len);
    }

    return result;
}