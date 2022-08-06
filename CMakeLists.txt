cmake_minimum_required(VERSION 3.21)

project(StringParser VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_library(StringParser STATIC "source/StringParser.cpp")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/header)

option(ENABLE_TESTS "Tests the program" OFF)

if(ENABLE_TESTS)
	enable_testing()

	add_executable(SeperateStringTest "test/SeperateStringTest.cpp")
	target_link_libraries(SeperateStringTest PUBLIC StringParser)

	add_test(NAME SeperateString1 COMMAND SeperateStringTest 1)
	add_test(NAME SeperateString2 COMMAND SeperateStringTest 2)
	add_test(NAME SeperateString3 COMMAND SeperateStringTest 3)
	add_test(NAME SeperateString4 COMMAND SeperateStringTest 4)
	add_test(NAME SeperateString5 COMMAND SeperateStringTest 5)

	add_test(NAME NewFeatureTest1 COMMAND SeperateStringTest 6)
	add_test(NAME NewFeatureTest2 COMMAND SeperateStringTest 7)
	add_test(NAME NewFeatureTest3 COMMAND SeperateStringTest 8)
endif()