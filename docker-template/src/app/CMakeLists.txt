
target_sources(${APP_EXE} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)

target_include_directories(${APP_EXE} PUBLIC
    "${PROJECT_BINARY_DIR}"
)