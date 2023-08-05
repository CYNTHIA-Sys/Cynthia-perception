cmake_minimum_required(VERSION 3.25)

project(Cynthia_perception)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(include)
include_directories(/usr/X11/include)

add_executable(Cynthia_perception
        include/cynthia-perception/hello-world.cpp
        src/hello2.cpp
        )

target_link_libraries(Cynthia_perception
        PRIVATE
        glfw
        OpenGL::GL
        )

target_compile_definitions(Cynthia_perception PRIVATE
        GL_SILENCE_DEPRECATION)