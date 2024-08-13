cmake_minimum_required(VERSION 3.24)
project(dpp_bot)

include(cmake_scripts/CPM.cmake)
add_subdirectory(vendor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    add_compile_options(/W4 /WX /MP /permissive-)
else()
    add_compile_options(-O0 -Wall -Werror -Wshadow -Wpedantic)

    if (NOT APPLE AND NOT DISABLE_SANITIZERS)
        add_compile_options(-fsanitize=address,undefined)
        link_libraries(
            asan
            ubsan
        )
    endif (NOT APPLE AND NOT DISABLE_SANITIZERS)
endif(WIN32)

add_subdirectory(lib)
add_subdirectory(app)

enable_testing()
add_subdirectory(test)
