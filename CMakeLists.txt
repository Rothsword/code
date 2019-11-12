cmake_minimum_required(VERSION 3.15)
project(code)

set(CMAKE_CXX_STANDARD 11)

add_executable(code main.cpp)
add_executable(chess chess.cpp)
add_executable(carpet carpet1003.cpp)
add_executable(pick square_pick.cpp)
add_executable(balloon blust_balloon.cpp)