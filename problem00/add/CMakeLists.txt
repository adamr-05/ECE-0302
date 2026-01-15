cmake_minimum_required(VERSION 3.10)
project(add)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STUDENT_SOURCE test_add.cpp Add.hpp Add.tpp)
set(SOURCE AbstractOperator.hpp ${STUDENT_SOURCE})

# create unittests
add_executable(test-add catch.hpp ${SOURCE})

enable_testing()

# unit tests
add_test(test-add test-add)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem_add.zip" --format=zip
       ${STUDENT_SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
     