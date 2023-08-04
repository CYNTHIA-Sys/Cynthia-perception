cmake_minimum_required(VERSION 3.25)
project(Cynthia_perception)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(include/cynthia-perception)
add_subdirectory(include/cynthia-perception)

add_executable(Cynthia_perception
        include/cynthia-perception/hello-world.cpp)
