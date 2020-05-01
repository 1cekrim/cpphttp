#include <session.hpp>

namespace cpphttp
{
Session::Session() : headers {}
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

Response::Response(const std::string_view& text, int status_code)
    : text(text),
      status_code(status_code)
{
    // Do nothing
}
}  // namespace cpphttp