#pragma once
#include <iostream>
#include <string>

namespace soundex {

uint32_t soundex_hash(std::string_view str);
std::string hash_ui32_to_str(uint32_t hash);
uint32_t hash_str_to_ui32t(const std::string &hash_str);

} // namespace soundex