#ifndef CPPHTTP_SESSION_HPP
#define CPPHTTP_SESSION_HPP

#include <headers.hpp>
#include <tcp.hpp>

namespace cpphttp
{
struct Response
{
    Response(const std::string_view& text, int status_cost);
    std::string raw;
    int status_code;
    // TODO: response header
};

class Session
{
 public:
    Session();
    Session(const Headers& headers);
    void open();
    void close();
    // TODO: cookie
    Response get(std::string_view url, const Headers& headers);

 private:
    Headers headers;
    Tcp tcp;
};
}  // namespace cpphttp

#endif  // CPPHTTP_SESSION_HPP