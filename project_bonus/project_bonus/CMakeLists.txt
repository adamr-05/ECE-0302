cmake_minimum_required(VERSION 3.10)
project(bonus)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_Database.cpp Database.hpp Database.tpp 
        BinarySearchTree.hpp BinarySearchTree.tpp 
        List.hpp List.tpp)

if(EXISTS "${PROJECT_SOURCE_DIR}/Node.tpp" AND EXISTS "${PROJECT_SOURCE_DIR}/Node.hpp")
    set(SOURCE ${SOURCE} Node.tpp Node.hpp)
endif()

add_executable(test-database catch.hpp AbstractList.hpp ${SOURCE})

enable_testing()

add_test(test-database test-database)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/project_bonus.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})  