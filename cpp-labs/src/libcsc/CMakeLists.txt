set(target_name time)

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