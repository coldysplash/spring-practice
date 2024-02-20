set(target_name soundex_groupby)
set(JSON_BuildTests OFF CACHE INTERNAL "")

add_executable(${target_name})

include(CompileOptions)
set_compile_options(${target_name})

target_sources(
  ${target_name}
  PRIVATE
    soundex_groupby/main.cpp
)

target_link_libraries(
  ${target_name}
  PRIVATE
    soundex
    nlohmann_json::nlohmann_json
)