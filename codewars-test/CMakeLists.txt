cmake_minimum_required(VERSION 3.10)

project(MyTest VERSION 1.0)

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
add_executable(${APP_EXE}
    ${CMAKE_CURRENT_SOURCE_DIR}/${MODULE}/module.c
    ${CMAKE_CURRENT_SOURCE_DIR}/${MODULE}/module_test.c
)

target_include_directories(${APP_EXE} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/${MODULE}
)

target_link_libraries(${APP_EXE} -lcriterion)


