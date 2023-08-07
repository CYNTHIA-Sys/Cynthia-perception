cmake_minimum_required(VERSION 3.25)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_STANDARD 11)

project(Cynthia_perception)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_REQUIRED_INCLUDES unistd.h)

function(check_term_for_256color)
    set(TERM_VAR_OUTPUT $ENV{TERM})
    message("${TERM_VAR_OUTPUT}")
    if(TERM_VAR_OUTPUT STREQUAL "xterm-256color")
        message(STATUS "VT100 support detected")
        set(terminal_vt100 1)
    else()
        message(STATUS "No VT100 support")
        set(terminal_vt100 0)
    endif()
endfunction()

check_term_for_256color()
if(terminal_vt100)
    message(STATUS "Building with 256 color support")
else()
    message(STATUS "Building without 256 color support")
endif()

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(/usr/X11/include)
include_directories(Dependencies)
include_directories(Dependencies/cute/include)



add_executable(Cynthia_perception
        include/cynthia-perception/core.h
        src/testCode.cpp
        src/window.cpp src/glad.c
        Dependencies/imgui/imgui.cpp
        Dependencies/imgui/backends/imgui_impl_glfw.cpp
        Dependencies/imgui/backends/imgui_impl_opengl3.cpp
        Dependencies/imgui/imgui_widgets.cpp
        Dependencies/imgui/imgui_tables.cpp
        Dependencies/imgui/imgui_draw.cpp
        Dependencies/imgui/imgui_demo.cpp)


target_link_libraries(Cynthia_perception
        PRIVATE
        glfw
        OpenGL::GL
        )

target_compile_definitions(Cynthia_perception
        PUBLIC GL_SILENCE_DEPRECATION
        CYNTHIA_USE_VT100) # TODO VT100 MUST FIX

#if(res)
#    target_compile_definitions(Cynthia_perception
#           PUBLIC CYNTHIA_USE_VT100)
#endif()