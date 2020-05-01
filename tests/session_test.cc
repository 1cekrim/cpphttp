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
    auto rep = sess.get("github.com", { { "Host", "github.com" } });
    std::cout << "rep.text: " << rep.text;
}