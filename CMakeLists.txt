cmake_minimum_required(VERSION 4.2)
project(Scanner)

set(CMAKE_CXX_STANDARD 20)

add_executable(Scanner main.cpp Scanner/scanner.hpp Scanner/tables.hpp Scanner/token.hpp Scanner/util.hpp)
