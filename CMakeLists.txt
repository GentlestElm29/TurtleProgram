cmake_minimum_required(VERSION 3.5)
project(ass1_turtleprogram)

set(CMAKE_CXX_STANDARD 14)

# have compiler give warnings, but not for signed/unsigned
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wno-sign-compare")

# Set default compile flags for GCC
if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -pedantic -Wall -Wextra")
endif(CMAKE_COMPILER_IS_GNUCXX)

add_executable(ass1_turtleprogram main.cpp turtleprogram.cpp turtleprogram.h turtleprogramtest.cpp)