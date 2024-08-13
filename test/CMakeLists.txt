# test config

CPMAddPackage(
    NAME googletest
    GITHUB_REPOSITORY google/googletest
    GIT_TAG release-1.12.1
    VERSION 1.12.1
    OPTIONS "INSTALL_GTEST OFF" "gtest_force_shared_crt"
)

set_target_properties(
    gmock
    gmock_main
    gtest
    gtest_main
    PROPERTIES
    FOLDER "GTEST"
)

include(AddTest.cmake)

AddTest(example example.cpp "")
