cmake_minimum_required(VERSION 3.10)
project(priorityqueue)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INTERFACES AbstractList.hpp AbstractSortedList.hpp AbstractPriorityQueue.hpp)
set(SOURCE test_PriorityQueue.cpp 
 List.hpp List.tpp
 ListIterator.hpp ListIterator.tpp
 SortedList.hpp SortedList.tpp)
set(QUEUE PriorityQueue.hpp PriorityQueue.tpp)

# include Node if present
if(EXISTS "${PROJECT_SOURCE_DIR}/Node.tpp" AND EXISTS "${PROJECT_SOURCE_DIR}/Node.hpp")
    set(SOURCE ${SOURCE} Node.tpp Node.hpp)
endif()

# create unittests
add_executable(test-priority-queue catch.hpp ${SOURCE} ${INTERFACES} ${QUEUE})
enable_testing()

# unit tests
add_test(test-priority-queue test-priority-queue)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem_priority_queue.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})   