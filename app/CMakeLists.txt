# app config

file(
    GLOB
    dpp_app_src
    src/main.cpp
)

add_executable(
    dpp_app
    ${dpp_app_src}
)

target_link_libraries(
    dpp_app
    PUBLIC
    dpp_bot_lib
)
