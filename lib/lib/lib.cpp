#include <boost/token_functions.hpp>
#include <lib/lib.hpp>

#include <boost/pfr/ops_fields.hpp>

#include <algorithm>
#include <charconv>
#include <utility>

using ::boost::pfr::eq_fields;

namespace xzr::lib
{
inline namespace v1
{
int add(int a, int b)
{
    return a + b;
}
bool operator==(const ymd& a, const ymd& b) noexcept
{
    return eq_fields(a, b);
}
bool operator!=(const ymd& a, const ymd& b) noexcept
{
    return !(a == b);
}
std::string to_str(const ymd& a)
{
    return std::to_string(a.y) + '.' + std::to_string(a.m) + '.' + std::to_string(a.d);
}
ymd from_str(const std::string_view s)
{
    const auto sep_y{std::find(s.cbegin(), s.cend(), '.')};
    int y{};
    std::from_chars(s.cbegin(), sep_y, y);

    const auto sep_m{std::find(sep_y + 1, s.cend(), '.')};
    int m{};
    std::from_chars(sep_y + 1, sep_m, m);

    int d{};
    std::from_chars(sep_m + 1, s.cend(), d);

    return {y, m, d};
}
}
}
