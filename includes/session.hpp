#ifndef CPPHTTP_SESSION_HPP
#define CPPHTTP_SESSION_HPP

#include <headers.hpp>

namespace cpphttp
{
class Session
{
 public:
    Session();

 private:
    Headers headers;
};
}  // namespace cpphttp

#endif  // CPPHTTP_SESSION_HPP