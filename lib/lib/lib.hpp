#pragma once

#include <string>
#include <string_view>

namespace xzr::lib
{
inline namespace v1
{
/// \brief returns the sum of a and b.
///
/// Just a simple sumation function with a nice documentation.
int add(int a, int b);
/// \brief holds a year, month and a day.
struct ymd
{
    int y;
    int m;
    int d;
};
bool operator==(const ymd& a, const ymd& b) noexcept;
bool operator!=(const ymd& a, const ymd& b) noexcept;
/// \brief converts a \ref ymd type to string.
///
/// \snippet lib/lib.test.cpp ymd_str_conv
std::string to_str(const ymd& a);
/// \brief converts string to a \ref ymd type.
///
/// \snippet lib/lib.test.cpp ymd_str_conv
ymd from_str(const std::string_view s);
}
}
