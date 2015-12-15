set(GTEST_ROOT $ENV{HOME}/usr/src/googletest)
include_directories(
    ${GTEST_ROOT}/include
    )
add_executable(gtest gtest.cpp)
target_link_libraries(gtest
    pthread
    ${GTEST_ROOT}/build/libgtest.a
    ${GTEST_ROOT}/build/libgtest_main.a
    )
