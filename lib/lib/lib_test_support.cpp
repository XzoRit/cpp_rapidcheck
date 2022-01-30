#include <lib/lib_test_support.hpp>

#include <string>

using ::rc::Gen;
using ::rc::gen::inRange;
using ::rc::gen::map;
using ::xzr::lib::to_str;

namespace xzr::lib
{
void showValue(const ymd& a, std::ostream& o)
{
    o << to_str(a).s;
}
void showValue(const ymd_str& a, std::ostream& o)
{
    o << '"' << a.s << '"';
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
    return map(rand_month(), [](int a) { return std::to_string(a); })
        .as("month_str");
}
Gen<std::string> rand_day_str()
{
    return map(rand_day(), [](int a) { return std::to_string(a); })
        .as("day_str");
}
}
