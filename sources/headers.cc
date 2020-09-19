#include <headers.hpp>
#include <iostream>

namespace cpphttp
{
Header::Header(const std::string_view& name, const std::string_view& value)
    : name(name),
      value(value)
{
    // Do nothing
}

std::string Header::to_string() const
{
    return name + ": " + value + "\r\n";
}

std::ostream& operator<<(std::ostream& os, const Header& header)
{
    os << header.to_string();
    return os;
}

Headers::Headers() : Headers({})
{
    // Do nothing
}

Headers::Headers(std::initializer_list<Header> il) : headers(il)
{
    // Do nothing
}

void Headers::set_method(Method m)
{
    switch (m)
    {
        case Method::GET:
            method = "GET";
            break;
        case Method::POST:
            method = "POST";
            break;
    }
}

void Headers::set_url(const std::string_view& url)
{
    // TODO: valid url?
    this->url = url;
}

void Headers::emplace_header(const std::string_view& name,
                             const std::string_view& value)
{
    headers.emplace_back(name, value);
}

void Headers::push_header(const Header& header)
{
    headers.push_back(header);
}

const std::vector<Header>& Headers::get_headers() const
{
    return headers;
}

Headers& Headers::operator<<(const Headers& target)
{
    headers.insert(headers.end(), target.headers.begin(), target.headers.end());
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Headers& headers)
{
    os << headers.method << ' ' << headers.url << " HTTP/1.1\r\n";
    for (const auto& header : headers.get_headers())
    {
        os << header;
    }
    return os;
}
}  // namespace cpphttp