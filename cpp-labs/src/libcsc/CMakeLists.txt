set(target_name time)
set(JSON_BuildTests OFF CACHE INTERNAL "")

add_library(${target_name} STATIC 
    libcsc/time/time.cpp
    libcsc/time/time.hpp
)

include(CompileOptions)
set_compile_options(${target_name})

target_include_directories(
    ${target_name}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(
    ${target_name}
    PRIVATE
)