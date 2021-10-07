cmake_minimum_required(VERSION 3.20)
project(erroror)

set(CMAKE_CXX_STANDARD 17)

add_executable(erroror main.cpp)
target_compile_options(erroror PRIVATE -Werror=unused-result)
