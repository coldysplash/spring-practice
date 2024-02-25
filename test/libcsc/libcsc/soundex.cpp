#include <libcsc/soundex/soundex.hpp>

#include <gtest/gtest.h>

#include <string>

TEST(soundex_hash, soundex_test) {
  std::string_view str = "HoweveR";
  uint32_t hash = soundex::soundex_hash(str);
  std::string str_hash = soundex::hash_ui32_to_str(hash);
  uint32_t convert_hash = soundex::hash_str_to_ui32t(str_hash);
  ASSERT_EQ(hash, convert_hash);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}