# -------------------------------------------------------
# test Library
# -------------------------------------------------------

cmake_minimum_required(VERSION 3.15)

set (LIB_NAME test_lib)

add_library(${LIB_NAME} STATIC ${CMAKE_CURRENT_LIST_DIR}/src/test.c)

target_include_directories(${LIB_NAME} PUBLIC include ${CMAKE_CURRENT_LIST_DIR}/inc)

# EOF
