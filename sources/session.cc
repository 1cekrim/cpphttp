#include <iostream>
#include <session.hpp>
#include <sstream>

namespace cpphttp
{
Session::Session()
    : headers({ { "User-Agent", "python-requests/2.23.0" },
                { "Accept-Encoding", "gzip, deflate" },
                { "Accept", "*/*" },
                { "Connection", "keep-alive" } }),
      tcp()
{
    // Do nothing
}

Session::Session(const Headers& headers) : headers(headers), tcp()
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

Response Session::get(std::string_view url, const Headers& headers)
{
    std::string host;
    // TODO: https
    if (url.substr(0, 7) == "http://")
    {
        int i;
        for (i = 7; i < url.length() && url[i] != '/'; ++i)
        {
            host.push_back(url[i]);
        }
        url.remove_prefix(i);
        std::cout << url;
    }
    else if (url.substr(0, 5) == "http:")
    {
        int i;
        for (i = 5; i < url.length() && url[i] != '/'; ++i)
        {
            host.push_back(url[i]);
        }
    }
    else
    {
        // TODO: NotSupportedProtocolException
    }

    Headers httpHeaders({ { "Host", host } });
    httpHeaders << this->headers << headers;

    httpHeaders.set_url(url);
    httpHeaders.set_method(Method::GET);

    std::stringstream ss;
    ss << httpHeaders << "\r\n";

    tcp.connect(host, 80);
    tcp.send(ss.str());
    std::string rep = tcp.recv();
    tcp.disconnect();

    // TODO: http response code
    // TODO: response header
    // TODO: cookie
    return Response(rep, 999);
}

Response::Response(const std::string_view& text, int status_code)
    : raw(text),
      status_code(status_code)
{
    // Do nothing
}
}  // namespace cpphttp
