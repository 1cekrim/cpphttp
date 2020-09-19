#include <doctest.h>

#include <iostream>
#include <session.hpp>

using namespace cpphttp;

TEST_CASE("session")
{
    Session sess;
}

TEST_CASE("get")
{
    Session sess;
    auto rep = sess.get("http://gaia.cs.umass.edu/wireshark-labs/HTTP-wireshark-file1.html", {});
    std::cout << "rep.raw: " << rep.raw;
}