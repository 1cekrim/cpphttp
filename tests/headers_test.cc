#include <doctest.h>

#include <headers.hpp>
#include <iostream>

using namespace cpphttp;

TEST_CASE("header")
{
    Header header { "Connection", "keep-alive" };
    std::cout << header;
}

TEST_CASE("headers_init")
{
    Headers headers { { "Host", "github.com" },
                      { "Connection", "keep-alive" } };
    headers.set_method(Method::GET);
    headers.set_url("http://github.com");

    std::cout << headers;
}
