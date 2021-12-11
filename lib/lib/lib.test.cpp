#include <lib/lib.hpp>

#include <rapidcheck.h>

#include <boost/test/unit_test.hpp>
// needs to be included after any boost test headers
#include <rapidcheck/boost_test.h>

#include <ostream>
#include <string>

using ::rc::Gen;
using ::rc::gen::arbitrary;
using ::rc::gen::construct;
using ::rc::gen::inRange;
using ::xzr::lib::add;
using ::xzr::lib::from_str;
using ::xzr::lib::to_str;
using ::xzr::lib::ymd;

namespace xzr::lib
{
void showValue(const ymd& a, std::ostream& o)
{
    o << a.y << '.' << a.m << '.' << a.d;
}
}
namespace
{
const Gen<int> rand_year{inRange(-9'999, 10'000).as("year")};
const Gen<int> rand_month{inRange(1, 12).as("month")};
const Gen<int> rand_day{inRange(1, 31).as("day")};
}
namespace rc
{
template <>
struct Arbitrary<xzr::lib::ymd>
{
    static Gen<xzr::lib::ymd> arbitrary()
    {
        return construct<xzr::lib::ymd>(::rand_year, ::rand_month, ::rand_day);
    }
};
}
namespace
{
BOOST_AUTO_TEST_SUITE(lib_tests)

RC_BOOST_PROP(exchanging_parameter_yields_same_result, (int a, int b))
{
    const int res_a{add(a, b)};
    const int res_b{add(b, a)};
    RC_ASSERT(res_a == res_b);
}

RC_BOOST_PROP(adding_one_twice_is_same_as_adding_two, (int a))
{
    const int res_a{add(add(a, 1), 1)};
    const int res_b{add(a, 2)};
    RC_ASSERT(res_a == res_b);
}

RC_BOOST_PROP(adding_zero_does_nothing, (int a))
{
    const int res_a{add(a, 0)};
    RC_ASSERT(res_a == a);
}

RC_BOOST_PROP(ymd_from_string, ())
{
    //! [ymd_str_conv]
    const auto rand_ymd{*arbitrary<ymd>()};

    const ymd actual{from_str(to_str(rand_ymd))};
    RC_ASSERT(rand_ymd == actual);
    //! [ymd_str_conv]
}

BOOST_AUTO_TEST_SUITE_END()
}
