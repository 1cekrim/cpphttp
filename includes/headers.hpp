#ifndef CPPHTTP_HEADER
#define CPPHTTP_HEADER

#include <iosfwd>
#include <string>
#include <string_view>
#include <vector>

namespace cpphttp
{
enum class Method
{
    GET,
    POST
};

struct Header
{
    Header(const std::string_view& name, const std::string_view& value);
    std::string to_string() const;

    friend std::ostream& operator<<(std::ostream& os, const Header& header);

    std::string name, value;
};

class Headers
{
 public:
    Headers();
    Headers(std::initializer_list<Header> il);
    void set_method(Method m);
    void set_url(const std::string_view& url);
    void emplace_header(const std::string_view& name, const std::string_view& value);
    void push_header(const Header& header);
    const std::vector<Header>& get_headers() const;
    std::string to_string() const;
    Headers& operator<<(const Headers& target);

    friend std::ostream& operator<<(std::ostream& os, const Headers& headers);

 private:
    std::vector<Header> headers;
    std::string method, url;
};
}  // namespace cpphttp

#endif  // CPPHTTP_HEADER