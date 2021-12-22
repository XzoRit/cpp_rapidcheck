#include <boost/token_functions.hpp>
#include <lib/lib.hpp>

#include <boost/pfr/ops_fields.hpp>

#include <algorithm>
#include <charconv>
#include <string>
#include <string_view>
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
bool operator==(const ymd_str& a, const ymd_str& b) noexcept
{
    return eq_fields(a, b);
}
bool operator!=(const ymd_str& a, const ymd_str& b) noexcept
{
    return !(a == b);
}
ymd_str to_str(const ymd& a)
{
    return {std::to_string(a.y) + '.' + std::to_string(a.m) + '.' + std::to_string(a.d)};
}
ymd from_str(const ymd_str& ymd)
{
    std::string_view sv{ymd.s};
    const auto sep_y{std::find(sv.cbegin(), sv.cend(), '.')};
    int y{};
    std::from_chars(sv.data(), sep_y, y);

    const auto sep_m{std::find(sep_y + 1, sv.cend(), '.')};
    int m{};
    std::from_chars(sep_y + 1, sep_m, m);

    int d{};
    std::from_chars(sep_m + 1, sv.cend(), d);

    return {y, m, d};
}
}
}
