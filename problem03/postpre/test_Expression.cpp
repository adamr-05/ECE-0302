#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include <string>
#include <stdexcept>

#include "Expression.hpp"

/* Testing provided functions, not run in autograder */
TEST_CASE("Test isPost", "[postpre]") {
  std::string postfix_valid = "ab+";
  std::string postfix_invalid_format = "a+b";
  std::string postfix_invalid_chars = "a2+";
  REQUIRE(Expression::isPost(postfix_valid));
  REQUIRE_FALSE(Expression::isPost(postfix_invalid_format));
  REQUIRE_FALSE(Expression::isPost(postfix_invalid_chars));
}

TEST_CASE("Test isPre", "[postpre]") {
  std::string prefix_valid = "+ab";
  std::string prefix_invalid_format = "a+b";
  std::string prefix_invalid_chars = "+a2";
  REQUIRE(Expression::isPre(prefix_valid));
  REQUIRE_FALSE(Expression::isPre(prefix_invalid_format));
  REQUIRE_FALSE(Expression::isPre(prefix_invalid_chars));
}

/* Provided test cases */
TEST_CASE("Postpre: Test setFromPrefix", "[postpre]") {
  // this is a long test case for autograder scoring purposes.
  // better practice is to break it up into multiple test cases
  // as indicated by the comments
  Expression e;

  // simple expression
  std::string prefix = "+ab";
  std::string test = "ab+";
  REQUIRE_NOTHROW(e.setFromPrefix(prefix));
  REQUIRE(e.getPrefix() == prefix);
  REQUIRE(e.getPostfix() == test);

  // other characters and operators
  prefix = "i";
  test = "i";
  REQUIRE_NOTHROW(e.setFromPrefix(prefix));
  REQUIRE(e.getPrefix() == prefix);
  REQUIRE(e.getPostfix() == test);

  prefix = "+Xi";
  test = "Xi+";
  REQUIRE_NOTHROW(e.setFromPrefix(prefix));
  REQUIRE(e.getPrefix() == prefix);
  REQUIRE(e.getPostfix() == test);

  prefix = "/RR";
  test = "RR/";
  REQUIRE_NOTHROW(e.setFromPrefix(prefix));
  REQUIRE(e.getPrefix() == prefix);
  REQUIRE(e.getPostfix() == test);

  // invalid expressions
  REQUIRE_THROWS_AS(e.setFromPrefix("+a1"), std::invalid_argument);
  REQUIRE_THROWS_AS(e.setFromPrefix("a+b"), std::invalid_argument);
}

TEST_CASE("Postpre: Test setFromPostfix simple", "[postpre]") {
  Expression e;
  std::string postfix = "ab+";
  std::string test = "+ab";

  REQUIRE_NOTHROW(e.setFromPostfix(postfix));
  REQUIRE(e.getPostfix() == postfix);
  REQUIRE(e.getPrefix() == test);
}

/* TODO: Your test cases here */
