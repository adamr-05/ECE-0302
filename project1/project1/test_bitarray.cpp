#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include <iostream>
#include "BitArray.hpp"

/* Provided test cases */
TEST_CASE( "Bitarray: Test default construction", "[bitarray]" ) {
    BitArray b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE( "Bitarray: Test construction with asString", "[bitarray]" ) {
    BitArray b;
    REQUIRE(b.asString() == "00000000");
}

TEST_CASE( "Bitarray: Test construction size", "[bitarray]" ) {
    BitArray b(64);
    std::string test_string(64, '0'); // 64-bit array of 0s
    REQUIRE(b.size() == 64);
    REQUIRE(b.good());
    REQUIRE(b.asString() == test_string);
}

TEST_CASE( "Bitarray: Test construction string", "[bitarray]" ) {
    std::string s("00101110000011000001101000001");
    BitArray b(s);
    REQUIRE(b.size() == s.size());
    REQUIRE(b.good());
    REQUIRE(b.asString() == s);
}

TEST_CASE( "Bitarray: Test set", "[bitarray]" ) {
    std::string test_string("10001000");
    BitArray b;
    b.set(3);
    b.set(7);
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.asString() == test_string);
}


/* Your test cases here */

TEST_CASE( "Bitarray: Test good", "[bitarray]")
{
    BitArray b;
    REQUIRE(b.good());
    b.set(9);
    REQUIRE_FALSE(b.good());
}

TEST_CASE( "Bitarray: Test size", "[bitarray]")
{
    BitArray b;
    REQUIRE(b.size() == 8);

    BitArray b1(16);
    REQUIRE(b1.size()==16);
}

TEST_CASE( "Bitarray: Test reset", "[bitarray]")
{
    std::string s("00000001");
    BitArray b(s);
    REQUIRE(b.test(0)==true);

    b.reset(0);
    REQUIRE(b.test(0)==false);

    b.reset(-1);
    REQUIRE_FALSE(b.good());
}

TEST_CASE( "Bitarray: Test toggle", "[bitarray]")
{
    std::string s("10000000");
    BitArray b(s);
    REQUIRE(b.test(7)==true);

    b.toggle(7);
    REQUIRE(b.test(7)==false);

    b.toggle(7);
    REQUIRE(b.test(7)==true);

    b.toggle(8);
    REQUIRE_FALSE(b.good());
}

TEST_CASE( "Bitarray: Test test", "[bitarray]")
{
    BitArray b;
    REQUIRE(b.test(0)==false);
    b.toggle(0);
    REQUIRE(b.test(0)==true);
}

TEST_CASE( "Bitarray: Test asString", "[bitarray]")
{
    BitArray b;
    b.set(0);
    b.set(1);
    REQUIRE(b.asString()=="00000011");

    std::string s("1000100110010");
    BitArray b1(s);
    REQUIRE(b1.asString()==s);
}