#include <doctest.h>

#include <iostream>
#include <tcp.hpp>
using namespace cpphttp;

TEST_CASE("dns_resolve")
{
    Tcp t;
    CHECK_NOTHROW(auto result = t.dns_resolve("github.com", 80));
}