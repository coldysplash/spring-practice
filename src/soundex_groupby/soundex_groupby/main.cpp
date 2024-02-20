#include <libcsc/soundex/soundex.hpp>

#include <nlohmann/json.hpp>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

struct Info {
  std::string name;
  std::string gender;
  std::string count;
};

using hash_names_info = std::map<uint32_t, Info>;

void parse_csv_file(const std::string &file_path) {
  std::ifstream input_file(file_path);
  if (!input_file.is_open()) {
    throw std::runtime_error("Error! Can't open input .csv file.\n");
  }
  hash_names_info names_infos;
  std::string line;
  while (std::getline(input_file, line)) {
    std::stringstream stream(line);
    std::string sub_str;
    std::vector<std::string> tokens;
    while (std::getline(stream, sub_str, ',')) {
      tokens.push_back(sub_str);
    }
    const uint32_t hash_name = soundex::soundex_hash(tokens[0]);
    names_infos[hash_name].name = tokens[0];
    names_infos[hash_name].gender = tokens[1];
    names_infos[hash_name].count = tokens[2];
  }
  input_file.close();

  std::ofstream output_file("output.json");
  using json = nlohmann::json;
  json json_list({});
  for (const auto &[hash, info] : names_infos) {
    const json curr_list = {{
        soundex::hash_ui32_to_str(hash),
        {info.name, info.gender, info.count},
    }};
    json_list.insert(curr_list.begin(), curr_list.end());
  }
  output_file << std::setw(2) << json_list << '\n';
}

int main(int argc, char **argv) {

  if (argc < 2 || argc > 2) {
    std::cout << "Error! Use ./app <path to inputfile.csv>\n";
    return -1;
  }

  try {
    parse_csv_file(argv[1]);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}