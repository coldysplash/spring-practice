#include <libcsc/soundex/soundex.hpp>

#include <algorithm>
#include <bitset>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace soundex {

void replace_consonants_to_digit(std::string &hash_str) {
  const std::unordered_map<char, char> consonants_digit = {
      {'b', '1'},
      {'f', '1'},
      {'p', '1'},
      {'v', '1'},
      {'c', '2'},
      {'g', '2'},
      {'j', '2'},
      {'k', '2'},
      {'q', '2'},
      {'s', '2'},
      {'x', '2'},
      {'z', '2'},
      {'d', '3'},
      {'t', '3'},
      {'l', '4'},
      {'m', '5'},
      {'n', '5'},
      {'r', '6'}};
  std::transform(hash_str.begin(), hash_str.end(), hash_str.begin(), tolower);
  std::transform(
      hash_str.begin() + 1,
      hash_str.end(),
      hash_str.begin() + 1,
      [&](const auto ch) {
        return consonants_digit.count(ch) ? consonants_digit.at(ch) : ch;
      });
}

void remove_vowels(std::string &hash_str) {
  const std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'y'};

  hash_str.erase(
      std::remove_if(
          hash_str.begin() + 1,
          hash_str.end(),
          [&](const auto ch) { return vowels.find(ch) != vowels.end(); }),
      hash_str.end());
}

void remove_duplicate_digits(std::string &hash_str) {
  hash_str.erase(
      std::unique(
          hash_str.begin(),
          hash_str.end(),
          [](char l, char r) {
            return ((std::isdigit(l) != 0 && std::isdigit(r) != 0) && l == r);
          }),
      hash_str.end());
}

uint32_t soundex_hash(std::string_view str) {
  const char first_ch = str.at(0);
  std::string hash_str(str);
  hash_str.erase(
      std::remove_if(
          hash_str.begin() + 1,
          hash_str.end(),
          [](const auto ch) { return (ch == 'h' || ch == 'w'); }),
      hash_str.end());

  replace_consonants_to_digit(hash_str);
  remove_duplicate_digits(hash_str);
  remove_vowels(hash_str);

  hash_str[0] = static_cast<char>(std::toupper(first_ch));

  if (hash_str.size() < 4) {
    hash_str.append(4 - hash_str.size(), '0');
  }

  return hash_str_to_ui32t(hash_str.substr(0, 4));
}

std::string hash_ui32_to_str(uint32_t hash) {
  std::string str_hash;
  for (int i = 3; i != -1; --i) {
    const u_char one_ch = hash >> static_cast<uint>(i * 8);
    str_hash += static_cast<char>(one_ch);
  }
  return str_hash;
}

uint32_t hash_str_to_ui32t(const std::string &hash_str) {
  uint32_t hash = 0;
  for (size_t i = 0; i < 4; ++i) {
    hash |= static_cast<u_char>(hash_str[i]);
    if (i < 3) {
      hash <<= static_cast<uint>(8);
    }
  }
  return hash;
}

} // namespace soundex