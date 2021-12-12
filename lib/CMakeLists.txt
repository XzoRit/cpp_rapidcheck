set(inc_dir ${CMAKE_CURRENT_SOURCE_DIR})

set(src_dir ${inc_dir}/lib)

# lib
add_library(lib)
add_library(lib::lib ALIAS lib)

target_sources(lib PRIVATE "${src_dir}/lib.cpp" "${src_dir}/lib.hpp")

target_include_directories(lib PUBLIC ${inc_dir})

target_link_libraries(lib PRIVATE Boost::boost)

# lib_test_support
add_library(lib_test_support)
add_library(lib::test_support ALIAS lib_test_support)

target_sources(
  lib_test_support PRIVATE "${src_dir}/lib_test_support.cpp"
                           "${src_dir}/lib_test_support.hpp"
)

target_include_directories(lib_test_support PUBLIC ${inc_dir})

target_link_libraries(lib_test_support PUBLIC rapidcheck lib)

# lib_test
add_executable(lib_test)

target_sources(
  lib_test PRIVATE "${src_dir}/lib.test.cpp" "${src_dir}/main.test.cpp"
)

target_link_libraries(
  lib_test PRIVATE lib::lib lib::test_support rapidcheck rapidcheck_boost_test
                   Boost::unit_test_framework
)

add_test(NAME lib::test COMMAND lib_test "--color_output=false")
