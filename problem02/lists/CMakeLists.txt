cmake_minimum_required(VERSION 3.10)
project(lists)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE ArrayList.hpp ArrayList.tpp test_ArrayList.cpp 
        LinkedList.hpp LinkedList.tpp test_LinkedList.cpp)

add_executable(test-array-list catch.hpp AbstractList.hpp ArrayList.hpp ArrayList.tpp test_ArrayList.cpp)
add_executable(test-linked-list catch.hpp Node.hpp Node.tpp AbstractList.hpp LinkedList.hpp LinkedList.tpp test_LinkedList.cpp)

enable_testing()

add_test(test-array-list test-array-list)
add_test(test-linked-list test-linked-list)


add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem_lists.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})