cmake_minimum_required(VERSION 2.6)

project (adventofcode)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g")

set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/${PROJECT_NAME}")

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link run_tests with what we want to test and the GTest and pthread library
add_executable(run_tests test_all.cpp)
target_link_libraries(run_tests ${GTEST_LIBRARIES} pthread)

add_executable(run_day run_day.cpp)
