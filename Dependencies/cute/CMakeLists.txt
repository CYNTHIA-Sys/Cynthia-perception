cmake_minimum_required(VERSION 3.25)
project(metatemplate_algorithms C)

set(CMAKE_CXX_STANDARD 20)

include_directories(metatemplate-algorithms)
include_directories(src/Data_Structures)
include_directories(include/cute)
include_directories(include/cute/include)

add_executable(main
        include/cute/debug.h test/utility_test.cpp)
