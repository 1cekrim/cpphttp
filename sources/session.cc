#include <session.hpp>

namespace cpphttp
{
Session::Session() : headers {}
{
    // Do nothing
}

Response::Response(const std::string_view& text, int status_code)
    : text(text),
      status_code(status_code)
{
    // Do nothing
}
}  // namespace cpphttp