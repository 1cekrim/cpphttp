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
    return name + ": " + value + '\n';
}

std::ostream& operator<<(std::ostream& os, const Header& header)
{
    os << header.to_string();
    return os;
}
}  // namespace cpphttp