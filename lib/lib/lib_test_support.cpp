#include <lib/lib_test_support.hpp>

using ::rc::Gen;
using ::rc::gen::container;
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
const Gen<int> rand_year{inRange(-9'999, 10'000).as("year")};
const Gen<int> rand_month{inRange(1, 13).as("month")};
const Gen<int> rand_day{inRange(1, 32).as("day")};
const Gen<std::string> rand_year_str{container<std::string>(4, inRange<char>('0', 'A'))};
const Gen<std::string> rand_month_str{map(rand_month, [](int a) { return std::to_string(a); }).as("month_str")};
const Gen<std::string> rand_day_str{map(rand_day, [](int a) { return std::to_string(a); }).as("day_str")};
}
