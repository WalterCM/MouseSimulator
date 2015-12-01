cmake_minimum_required(VERSION 3.3)
project(MouseSimulator)

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(LINUX_TRUE ON)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(WINDOWS_TRUE ON)
endif()

# C++ Flags
if (LINUX_TRUE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lX11 -lXtst")
elseif (WINDOWS_TRUE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Find any version 2.X of SFML
find_package(SFML REQUIRED Window)

# Set executable directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

if (LINUX_TRUE)
    set(MOUSE_FILES src/MouseLinux.cpp src/MouseLinux.hpp)
elseif (WINDOWS_TRUE)
    set(MOUSE_FILES src/MouseWindows.cpp src/MouseWindows.hpp)
endif()

set(SOURCE_FILES src/Main.cpp
        src/Program.cpp
        src/Program.hpp
        src/Joystick.cpp
        src/Joystick.hpp
        ${MOUSE_FILES})

add_executable(MouseSimulator ${SOURCE_FILES})

# Link SFML library
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(MouseSimulator ${SFML_LIBRARY})
endif()