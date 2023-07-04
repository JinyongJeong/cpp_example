cmake_minimum_required(VERSION 3.10)
project(design_pattern_example)

set(CMAKE_CXX_STANDARD 17)

# Build all example file in the design pattern folder
file(GLOB_RECURSE example_sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/example/design_pattern example/design_pattern/*.cpp)
foreach(example_source ${example_sources})
	string(REPLACE ".cpp" "" example_name ${example_source})
        set(example_binary_name ${example_name})

        add_executable(${example_binary_name} example/design_pattern/${example_source})
endforeach()

# Build all example file in the cpp example folder
file(GLOB_RECURSE example_sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/example/cpp_example example/cpp_example/*.cpp)
foreach(example_source ${example_sources})
	string(REPLACE ".cpp" "" example_name ${example_source})
        set(example_binary_name ${example_name})

        add_executable(${example_binary_name} example/cpp_example/${example_source})
endforeach()