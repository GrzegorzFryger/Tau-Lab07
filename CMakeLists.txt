

cmake_minimum_required(VERSION 3.5)

project(Tau_Lab07 LANGUAGES CXX VERSION 0.0.1)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra")
include_directories("${PROJECT_SOURCE_DIR}/src")
file(GLOB_RECURSE lib_SOURCES "src/*.cpp" "src/*/*.cpp")
file(GLOB_RECURSE test_SOURCES "test/*.cpp")
add_library(simpleDataBase SHARED ${lib_SOURCES})
install (TARGETS simpleDataBase DESTINATION lib)

find_package(Catch2 REQUIRED)

add_executable(Tau_Lab07-test ${test_SOURCES})
target_link_libraries(Tau_Lab07-test simpleDataBase Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(Tau_Lab07-test)