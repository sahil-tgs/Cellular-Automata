# CMakeLists.txt
cmake_minimum_required(VERSION 3.12)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 11)

# Find GTK3
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Include directories
include_directories(include ${GTK3_INCLUDE_DIRS})

# Specify the source files
set(SOURCE_FILES
    src/main.cpp
    src/GameOfLife.cpp
    src/Grid.cpp
)

# Create an executable
add_executable(game_of_life ${SOURCE_FILES})

# Link against GTK3
target_link_libraries(game_of_life PRIVATE ${GTK3_LIBRARIES})
