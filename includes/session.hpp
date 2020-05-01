#ifndef CPPHTTP_SESSION_HPP
#define CPPHTTP_SESSION_HPP

#include <headers.hpp>
#include <tcp.hpp>

namespace cpphttp
{
class Session
{
 public:
    Session();
    void open();
    void close();

 private:
    Headers headers;
    Tcp tcp;
};

struct Response
{
    Response(const std::string_view& text, int status_cost);
    std::string text;
    int status_code;
};
}  // namespace cpphttp

#endif  // CPPHTTP_SESSION_HPP