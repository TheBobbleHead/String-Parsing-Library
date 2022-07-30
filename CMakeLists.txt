cmake_minimum_required(VERSION 3.21)

project(StringParser VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_library(StringParser STATIC "source/StringParser.cpp")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/header)

enable_testing()

add_executable(SeperateStringTest "test/SeperateStringTest.cpp")
target_link_libraries(SeperateStringTest PUBLIC StringParser)

add_test(NAME SeperateString1 COMMAND SeperateStringTest 1)
add_test(NAME SeperateString2 COMMAND SeperateStringTest 2)
add_test(NAME SeperateString3 COMMAND SeperateStringTest 3)
add_test(NAME SeperateString4 COMMAND SeperateStringTest 4)
add_test(NAME SeperateString5 COMMAND SeperateStringTest 5)