target_sources(${APP_EXE} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/module.c
)

target_include_directories(${APP_EXE} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)