cmake_minimum_required(VERSION 3.3)
project(mouseSimulator)

# C++ Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lX11 -lXtst")

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Find any version 2.X of SFML
find_package(SFML REQUIRED Graphics Window)

# Set executable directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(SOURCE_FILES main.cpp Mouse.cpp Mouse.hpp Joystick.cpp Joystick.hpp Program.cpp Program.hpp)

add_executable(mouseSimulator ${SOURCE_FILES})

# Link SFML library
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(mouseSimulator ${SFML_LIBRARY})
endif()