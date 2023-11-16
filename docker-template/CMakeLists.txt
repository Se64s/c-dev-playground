cmake_minimum_required(VERSION 3.15)

project(MyApp VERSION 1.0)

# Define user app output
set (APP_EXE ${CMAKE_PROJECT_NAME}.out)

# Define gcc compiler flags
set (USER_COMPILER_FLAGS -Wall -Wextra -Wshadow -Wformat=2 -Wunused -O0 -g)

# Compiler definition
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_BUILD_TYPE Debug)

# Add user flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${USER_COMPILER_FLAGS}")

# Create output exe
add_executable(${APP_EXE})

# Add sources to exe
add_subdirectory(src)

# EOF
