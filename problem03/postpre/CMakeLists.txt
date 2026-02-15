cmake_minimum_required(VERSION 3.10)
project(postpre)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_Expression.cpp Expression.hpp Expression.cpp)

add_executable(test-expression catch.hpp AbstractExpression.hpp ${SOURCE})

enable_testing()

add_test(test-expression test-expression)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem_postpre.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})