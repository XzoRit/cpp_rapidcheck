#include <lib/lib.hpp>
#include <lib/lib_test_support.hpp>

#include <boost/program_options.hpp>

#include <rapidcheck.h>

#include <iostream>

using ::rc::check;
using ::xzr::lib::add;
using ::xzr::lib::test::rand_day;
using ::xzr::lib::test::rand_day_str;
using ::xzr::lib::test::rand_month;
using ::xzr::lib::test::rand_month_str;
using ::xzr::lib::test::rand_year;
using ::xzr::lib::test::rand_year_str;

namespace po = boost::program_options;

int main(int ac, char* av[])
{
    std::cout << "Hello app\n";

    try
    {
        po::options_description desc("Allowed options");
        desc.add_options()("help", "produce help message");

        po::variables_map vm;
        po::store(po::parse_command_line(ac, av, desc), vm);
        po::notify(vm);

        if (vm.count("help"))
        {
            std::cout << desc << "\n";
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch (...)
    {
        std::cerr << "Exception of unknown type!\n";
    }

    check("rand_year", []() { RC_TAG(*rand_year); });
    check("rand_month", []() { RC_TAG(*rand_month); });
    check("rand_day", []() { RC_TAG(*rand_day); });

    check("rand_year_str", []() { RC_TAG(*rand_year_str); });
    check("rand_month_str", []() { RC_TAG(*rand_month_str); });
    check("rand_day_str", []() { RC_TAG(*rand_day_str); });

    return add(0, 0);
}
