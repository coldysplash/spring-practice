add_executable(
  time_test
  libcsc/time.cpp
)

target_link_libraries(
  time_test
  GTest::gtest_main
  time
)

include(GoogleTest)
gtest_discover_tests(time_test)