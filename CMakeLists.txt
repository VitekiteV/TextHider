cmake_minimum_required(VERSION 3.10)

project(TextHider VERSION 1.0)

add_executable(TextHider src/main.cpp)

add_library(TextHider_lib STATIC src/TextHider_lib.cpp src/TextHider_lib.h)

target_compile_features(TextHider PRIVATE cxx_std_17)

target_link_libraries(TextHider PRIVATE TextHider_lib)