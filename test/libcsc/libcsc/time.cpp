#include <libcsc/time/time.hpp>

#include <gtest/gtest.h>

TEST(arithmetic_operators_Time, time_test) {
  const times::Time t_1 = 500;
  const times::TimeSpan t_2 = 300;
  const times::Time res_t = t_1 + t_2;
  ASSERT_EQ(res_t.get_time(), 800);
  const times::Time res_t_2 = t_1 - t_2;
  ASSERT_EQ(res_t_2.get_time(), 200);
}

TEST(arithmetic_operators_TimeSpan, time_test) {
  const times::Time t_1 = 500;
  const times::Time t_2 = 300;
  const times::TimeSpan t_span = t_1 - t_2;
  ASSERT_EQ(t_span.get_spantime(), 200);
  const times::TimeSpan t_span_2 = 50;
  const times::TimeSpan res_t_span_1 = t_span + t_span_2;
  const times::TimeSpan res_t_span_2 = t_span - t_span_2;
  ASSERT_EQ(res_t_span_1.get_spantime(), 250);
  ASSERT_EQ(res_t_span_2.get_spantime(), 150);
}
TEST(comparison_operators_Time, time_test) {
  const times::Time t_1 = 52;
  const times::Time t_2 = 52;
  const bool equally = t_1 == t_2;
  const bool not_equally = t_1 != t_2;
  ASSERT_EQ(equally, true);
  ASSERT_EQ(not_equally, false);
  const times::Time tt_1 = 10;
  const times::Time tt_2 = 52;
  const bool more_less = tt_1 < tt_2;
  const bool more_less_2 = tt_1 > tt_2;
  ASSERT_EQ(more_less, true);
  ASSERT_EQ(more_less_2, false);
}
TEST(comparison_operators_TimeSpan, time_test) {
  const times::TimeSpan t_1 = 52;
  const times::TimeSpan t_2 = 52;
  const bool equally = t_1 == t_2;
  const bool not_equally = t_1 != t_2;
  ASSERT_EQ(equally, true);
  ASSERT_EQ(not_equally, false);
  const times::TimeSpan tt_1 = 10;
  const times::TimeSpan tt_2 = 52;
  const bool more_less = tt_1 < tt_2;
  const bool more_less_2 = tt_1 > tt_2;
  ASSERT_EQ(more_less, true);
  ASSERT_EQ(more_less_2, false);
}

TEST(literals_test, time_test) {
  using namespace times::literals;
  const auto t_d = 1_d;
  const auto t_h = 2_h;
  const auto t_m = 30_m;
  const auto t_s = 20_s;
  ASSERT_EQ(t_d.get_time(), 24 * 3600);
  ASSERT_EQ(t_h.get_time(), 2 * 3600);
  ASSERT_EQ(t_m.get_time(), 1800);
  ASSERT_EQ(t_s.get_time(), 20);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}