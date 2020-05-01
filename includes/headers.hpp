#ifndef CPPHTTP_HEADER
#define CPPHTTP_HEADER

#include <iosfwd>
#include <string>
#include <string_view>

namespace cpphttp
{
struct Header
{
    Header(const std::string_view& name, const std::string_view& value);
    std::string to_string() const;

    friend std::ostream& operator<<(std::ostream& os, const Header& header);

    std::string name, value;
};
}  // namespace cpphttp

#endif  // CPPHTTP_HEADER