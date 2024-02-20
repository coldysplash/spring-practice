#pragma once
#include <iostream>
#include <string>

namespace soundex {

void replace_consonants_to_digit(std::string &hash_str);
void remove_vowels(std::string &hash_str);
void remove_duplicate_digits(std::string &hash_str);

uint32_t soundex_hash(std::string_view str);

std::string hash_ui32_to_str(uint32_t hash);
uint32_t hash_str_to_ui32t(const std::string &hash_str);

} // namespace soundex