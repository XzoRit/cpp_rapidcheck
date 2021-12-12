#pragma once

#include <lib/lib.hpp>

#include <rapidcheck.h>

#include <ostream>
#include <string>

namespace xzr::lib
{
void showValue(const ymd& a, std::ostream& o);
}
namespace xzr::lib::test
{
extern const ::rc::Gen<int> rand_year;
extern const ::rc::Gen<int> rand_month;
extern const ::rc::Gen<int> rand_day;
extern const ::rc::Gen<std::string> rand_year_str;
extern const ::rc::Gen<std::string> rand_month_str;
extern const ::rc::Gen<std::string> rand_day_str;
}
namespace rc
{
template <>
struct Arbitrary<::xzr::lib::ymd>
{
    static Gen<::xzr::lib::ymd> arbitrary()
    {
        return ::rc::gen::construct<::xzr::lib::ymd>(::xzr::lib::test::rand_year,
                                                     ::xzr::lib::test::rand_month,
                                                     ::xzr::lib::test::rand_day);
    }
};
}
