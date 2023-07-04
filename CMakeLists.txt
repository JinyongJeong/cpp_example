cmake_minimum_required(VERSION 3.10)
project(design_pattern_example)

set(CMAKE_CXX_STANDARD 17)

# Build all example file in the example folder
file(GLOB_RECURSE example_sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/example example/*.cpp)
foreach(example_source ${example_sources})
	string(REPLACE ".cpp" "" example_name ${example_source})
        set(example_binary_name ${example_name})

        add_executable(${example_binary_name} example/${example_source})
endforeach()