#include <libcsc/soundex/soundex.hpp>

#include <gtest/gtest.h>

#include <string>

TEST(algo_methods_in_hash, soundex_test) {

  {
    std::string test_str = "QbfpVCGJKqsxzdtlmnr";
    soundex::replace_consonants_to_digit(test_str);
    std::string expected_res = "q111122222222334556";

    ASSERT_EQ(test_str, expected_res);
  }
  {
    std::string test_str = "q111122222222334556";
    soundex::remove_duplicate_digits(test_str);
    std::string expected_res = "q123456";

    ASSERT_EQ(test_str, expected_res);
  }
  {
    std::string test_str = "qaeiouy";
    soundex::remove_vowels(test_str);
    std::string expected_res = "q";

    ASSERT_EQ(test_str, expected_res);
  }
}

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