include_guard(GLOBAL)

include(GoogleTest REQUIRED)
include(CTest REQUIRED)

function(AddTest TestName src libs)
    set(fullName ${TestName})
    set(_runtime ${fullName}_Tests)

    add_executable(
        ${_runtime}
        ${src}
    )

    set_target_properties(
        ${_runtime}
        PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        FOLDER "tests/"
    )

    target_include_directories(
        ${_runtime}
        PUBLIC
        GTest::gtest_main
    )

    target_link_libraries(
        ${_runtime}
        PUBLIC
        ${SANITIZER_LIBS}
        GTest::gtest_main
        ${libs}
    )

    gtest_discover_tests(
        ${_runtime}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
endfunction(AddTest TestName src libs)
