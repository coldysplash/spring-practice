#include <../../../src/libcsc/libcsc/list/list.hpp>

#include <gtest/gtest.h>

#include <vector>

TEST(list_test, iterator_test) {

  list::List<int> eq_list{1, 2, 3, 4};
  list::List<int>::iterator beg = eq_list.begin();
  list::List<int>::iterator end = eq_list.end();

  list::List<int> expected(beg, end);

  ASSERT_EQ(eq_list, expected);
}

TEST(list_test, front_back_test) {

  list::List<int> eq_list{1, 2, 3, 4};

  ASSERT_EQ(eq_list.front(), 1);
  ASSERT_EQ(eq_list.back(), 4);
}

TEST(list_test, push_test) {
  {
    list::List<int> eq_list{1, 2, 3};
    eq_list.push_back(5);
    list::List<int> expected{1, 2, 3, 5};
    ASSERT_EQ(eq_list, expected);
  }
  {
    list::List<int> eq_list{1, 2, 3};
    eq_list.push_front(5);
    list::List<int> expected{5, 1, 2, 3};
    ASSERT_EQ(eq_list, expected);
  }
}

TEST(list_test, empty_size_test) {
  list::List<int> eq_list{1, 2, 3};
  ASSERT_EQ(eq_list.empty(), false);
  list::List<int> eq_list_1{};
  ASSERT_EQ(eq_list_1.empty(), true);
  ASSERT_EQ(eq_list.size(), 3);
  ASSERT_EQ(eq_list_1.size(), 0);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}