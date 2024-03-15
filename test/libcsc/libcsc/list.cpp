#include <../../../src/libcsc/libcsc/list/list.hpp>

#include <gtest/gtest.h>

#include <vector>

TEST(list_test, push_test) {
  list::List<int> eq_list{1, 2, 3};
  eq_list.push_back(5);
  list::List<int> expected{1, 2, 3, 5};
  ASSERT_EQ(eq_list, expected);
}

TEST(list_test, iterator_test) {

  list::List<int> eq_list{1, 2, 3, 4};
  list::List<int>::iterator beg = eq_list.begin();
  list::List<int>::iterator end = eq_list.end();

  list::List<int> expected(beg, end);

  ASSERT_EQ(eq_list, expected);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}