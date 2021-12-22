#include <lib/lib.hpp>
#include <lib/lib_test_support.hpp>

#include <boost/program_options.hpp>

#include <rapidcheck.h>

#include <iostream>

using ::rc::check;
using ::xzr::lib::add;
using ::xzr::lib::ymd;
using ::xzr::lib::ymd_str;

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
            return 0;
        }

        check("rand_ymd", [](const ymd& a) { RC_TAG(a); });
        check("rand_ymd_str", [](const ymd_str& a) { RC_TAG(a); });

        return add(0, 0);
    }
    catch (const std::exception& e)
    {
        std::cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch (...)
    {
        std::cerr << "Exception of unknown type!\n";
        return 2;
    }
}
