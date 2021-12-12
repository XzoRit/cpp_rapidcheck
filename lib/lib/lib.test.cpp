#include <lib/lib.hpp>
#include <lib/lib_test_support.hpp>

#include <rapidcheck.h>

#include <boost/test/unit_test.hpp>
// needs to be included after any boost test headers
#include <rapidcheck/boost_test.h>

#include <ostream>
#include <string>

using ::xzr::lib::add;
using ::xzr::lib::from_str;
using ::xzr::lib::to_str;
using ::xzr::lib::ymd;
using ::xzr::lib::test::rand_day_str;
using ::xzr::lib::test::rand_month_str;
using ::xzr::lib::test::rand_year_str;

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

RC_BOOST_PROP(ymd_from_string, (ymd rand_ymd))
{
    //! [ymd_str_conv]
    RC_ASSERT(rand_ymd == from_str(to_str(rand_ymd)));
    //! [ymd_str_conv]
}

RC_BOOST_PROP(ymd_to_string, ())
{
    std::string rand_ymd_str{*rand_year_str + '.' + *rand_month_str + '.' + *rand_day_str};
    RC_ASSERT(rand_ymd_str == to_str(from_str(rand_ymd_str)));
}

BOOST_AUTO_TEST_SUITE_END()
}
