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

add_executable(
  soundex_test
  libcsc/soundex.cpp
)

target_link_libraries(
  soundex_test
  GTest::gtest_main
  soundex
)

gtest_discover_tests(soundex_test)

add_executable(
  list_test
  libcsc/list.cpp
)

target_link_libraries(
  list_test
  GTest::gtest_main
)

gtest_discover_tests(list_test)