add_executable(app_exe)

target_sources(app_exe PRIVATE "main.cpp")

target_link_libraries(
  app_exe PRIVATE lib::lib lib::test_support Boost::program_options rapidcheck
)

add_test(NAME app::exe COMMAND app_exe "--help")
