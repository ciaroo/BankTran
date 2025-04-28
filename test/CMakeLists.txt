cmake_minimum_required(VERSION 3.10)
set(CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH
        "/opt/homebrew/opt/googletest"
        ${CMAKE_PREFIX_PATH})


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES runAllTests.cpp
        test_bank.cpp)

message(${SOURCE_FILES})
add_executable(runAllTests ${SOURCE_FILES})
target_link_libraries(runAllTests ${GTEST_BOTH_LIBRARIES} core)
