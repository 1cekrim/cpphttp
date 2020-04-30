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
    if (socket == INVALID_SOCKET)
    {
        throw std::runtime_error("Init first.");
    }

    // TODO: implement connect
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
