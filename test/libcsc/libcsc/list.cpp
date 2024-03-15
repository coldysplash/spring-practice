#include <../../../src/libcsc/libcsc/list/list.hpp>

#include <gtest/gtest.h>

#include <vector>

TEST(list_test, _test) {
  list::List<int> my_list{1, 2, 3};
  my_list.push_back(5);
  std::vector<int> eq_list;
  for (auto it = my_list.begin(); it != my_list.end(); it++) {
    eq_list.push_back(*it);
  }
  std::vector<int> expected{1, 2, 3, 5};
  ASSERT_EQ(eq_list, expected);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}