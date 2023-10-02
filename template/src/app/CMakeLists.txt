
target_sources(${APP_EXE} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)

configure_file(AppConfig.h.in AppConfig.h)
