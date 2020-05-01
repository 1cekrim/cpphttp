#include <doctest.h>

#include <headers.hpp>
#include <iostream>

using namespace cpphttp;

TEST_CASE("header")
{
    Header header { "Connection", "keep-alive" };
    std::cout << header;
}