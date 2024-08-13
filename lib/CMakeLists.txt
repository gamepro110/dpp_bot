# lib config

file(
    GLOB
    dpp_bot_lib_src
    src/*.cpp
    src/*.hpp
)

add_library(
    dpp_bot_lib
    ${dpp_bot_lib_src}
)

target_link_libraries(
    dpp_bot_lib
    PUBLIC
    dpp
)

target_include_directories(
    dpp_bot_lib
    PUBLIC
    ./src
    ${DPP_SOURCE_DIR}/include
)
