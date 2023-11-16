#-------------------
# App modules
#-------------------

add_subdirectory(test)

# Link compiled libraries
target_link_libraries(${APP_EXE} test_lib)

# EOF
