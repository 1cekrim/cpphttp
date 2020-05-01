#include <session.hpp>
#include <sstream>

namespace cpphttp
{
Session::Session() : headers(), tcp()
{
    // Do nothing
}

void Session::open()
{
    // TODO: open
}

void Session::close()
{
    // TODO: close
}

Response Session::get(const std::string_view& url, const Headers& headers)
{
    // TODO: merge this->headers and headers
    // TODO: https
    tcp.connect(std::string(url), 80);
    std::stringstream ss;
    ss << this->headers;
    tcp.send(ss.str());
    std::string rep = tcp.recv();
    tcp.disconnect();

    // TODO: http response code
    // TODO: response header
    // TODO: cookie
    return Response(rep, 999);
}

Response::Response(const std::string_view& text, int status_code)
    : text(text),
      status_code(status_code)
{
    // Do nothing
}
}  // namespace cpphttp
