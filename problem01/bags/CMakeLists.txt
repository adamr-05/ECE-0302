cmake_minimum_required(VERSION 3.10)
project(bags)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIMITED_SIZE_BAG_SOURCE LimitedSizeBag.hpp LimitedSizeBag.tpp test_LimitedSizeBag.cpp)
set(DYNAMIC_BAG_SOURCE DynamicBag.hpp DynamicBag.tpp test_DynamicBag.cpp)

# create unittests
add_executable(test-limited-size-bag catch.hpp AbstractBag.hpp ${LIMITED_SIZE_BAG_SOURCE})
add_executable(test-dynamic-bag catch.hpp AbstractBag.hpp ${DYNAMIC_BAG_SOURCE})

enable_testing()

# unit tests
add_test(test-limited-size-bag test-limited-size-bag) 
add_test(test-dynamic-bag test-dynamic-bag)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem_bags.zip" --format=zip
       ${DYNAMIC_BAG_SOURCE}
       ${LIMITED_SIZE_BAG_SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
      