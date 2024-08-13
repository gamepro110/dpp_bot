cmake_minimum_required(VERSION 3.24)
project(dpp_bot)

include(cmake_scripts/CPM.cmake)
add_subdirectory(vendor)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(lib)
add_subdirectory(app)

enable_testing()
add_subdirectory(test)
