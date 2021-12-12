#include <lib/lib_test_support.hpp>
#include <string>

using ::rc::Gen;
using ::rc::gen::inRange;
using ::rc::gen::map;

namespace xzr::lib
{
void showValue(const ymd& a, std::ostream& o)
{
    o << a.y << '.' << a.m << '.' << a.d;
}
}
namespace xzr::lib::test
{
Gen<int> rand_year()
{
    return inRange(-9'999, 10'000).as("year");
}
Gen<int> rand_month()
{
    return inRange(1, 13).as("month");
}
Gen<int> rand_day()
{
    return inRange(1, 32).as("day");
}
Gen<std::string> rand_year_str()
{
    return map(rand_year(), [](int a) { return std::to_string(a); });
}
Gen<std::string> rand_month_str()
{
    return map(rand_month(), [](int a) { return std::to_string(a); }).as("month_str");
}
Gen<std::string> rand_day_str()
{
    return map(rand_day(), [](int a) { return std::to_string(a); }).as("day_str");
}
Gen<std::string> rand_ymd_str()
{
    return ::rc::gen::apply(
        [](const std::string& y, const std::string& m, const std::string& d) { return y + '.' + m + '.' + d; },
        rand_year_str(),
        rand_month_str(),
        rand_day_str());
}
}
