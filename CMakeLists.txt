cmake_minimum_required(VERSION 3.12)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 11)

# Specify the source files
set(SOURCE_FILES
    src/main.cpp
    src/GameOfLife.cpp
    src/Grid.cpp
)

# Create an executable
add_executable(game_of_life ${SOURCE_FILES})

# Include the 'include' directory for header files
target_include_directories(game_of_life PRIVATE include)
