cmake_minimum_required(VERSION 3.8.2 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

project(cpphtdtp)

include_directories(includes/)
include_directories(libraries/doctest/doctest)

add_subdirectory(libraries/doctest)
add_subdirectory(sources)
add_subdirectory(tests)