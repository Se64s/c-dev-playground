add_library(TestMod test_mod.c)

set(LIB_FLAGS -Wall -Wextra -Wshadow -Wformat=2 -Wunused -O0 -g)

target_include_directories(TestMod
                            INTERFACE
                            ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(TestMod PUBLIC ${LIB_FLAGS})

# setup the version numbering
set_property(TARGET TestMod PROPERTY VERSION "1.0.0")
set_property(TARGET TestMod PROPERTY SOVERSION "1")
