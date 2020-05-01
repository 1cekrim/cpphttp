#include <doctest.h>

#include <iostream>
#include <tcp.hpp>
using namespace cpphttp;

TEST_CASE("dns_resolve")
{
    Tcp t;
    CHECK_NOTHROW(auto result = t.dns_resolve("github.com", 80));
}

TEST_CASE("connect")
{
    Tcp t;
    CHECK_NOTHROW(t.connect("github.com", 80));
}

TEST_CASE("send")
{
    Tcp t;
    t.connect("github.com", 80);
    t.send("GET http://github.com\n");
    t.disconnect();
}

TEST_CASE("send_and_recv")
{
    Tcp t;
    t.connect("github.com", 80);
    t.send("GET http://github.com\n");
    t.disconnect();
}