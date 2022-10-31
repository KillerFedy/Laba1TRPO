#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Integer.h"

using namespace arbitary_precision_arithmetic;

TEST_CASE("Test1") {
    REQUIRE(Integer(6) - Integer(2) == 4);
}

TEST_CASE("Test2") {
    REQUIRE(Integer(120) + Integer(130) == 250);
}

TEST_CASE("Test3") {
    Integer a(300);
    Integer b(200);
    a += b;
    REQUIRE(a == 500);
}

TEST_CASE("Test4") {
    REQUIRE(Integer(LLONG_MAX) + Integer(LLONG_MAX) + Integer(LLONG_MAX) + Integer(LLONG_MAX) == Integer(LLONG_MAX) + Integer(LLONG_MAX) + Integer(LLONG_MAX) + Integer(LLONG_MAX));
}


TEST_CASE("Test5") {
    Integer a(300);
    Integer b(200);
    a -= b;
    REQUIRE(a == 100);
}

TEST_CASE("Test6") {
    Integer a(300);
    Integer b(200);
    a = b;
    REQUIRE(a == 200);
}

//TEST_CASE("Test7") {
//    Integer a(300);
//    REQUIRE(-a == -300);
//}

TEST_CASE("Test8") {
    Integer a(300);
    a++;
    REQUIRE(a == 301);
}

TEST_CASE("Test9") {
    Integer a(300);
    a--;
    REQUIRE(a == 299);
}

TEST_CASE("Test10") {
    Integer a(300);
    Integer b(200);
    a += -b;
    REQUIRE(a == 100);
}

TEST_CASE("Test11") {
    Integer a(300);
    Integer b(200);
    REQUIRE(a > b);
}

TEST_CASE("Test12") {
    Integer a(300);
    Integer b(200);
    REQUIRE(b < a);
}

TEST_CASE("Test13") {
    Integer a(300);
    Integer b(300);
    REQUIRE(b == a);
}

TEST_CASE("Test14") {
    Integer a(300);
    Integer b(300);
    REQUIRE(b >= a);
}

TEST_CASE("Test15") {
    Integer a(300);
    Integer b(300);
    REQUIRE(b <= a);
}

TEST_CASE("Test16") {
    Integer a(100);
    Integer b(300);
    REQUIRE(b != a);
}

TEST_CASE("Test17") {
    Integer a(100);
    REQUIRE(a < 300);
}

TEST_CASE("Test18") {
    Integer a(1000);
    REQUIRE(a > 300);
}

TEST_CASE("Test19") {
    Integer a(300);
    REQUIRE(a <= 300);
}

TEST_CASE("Test20") {
    Integer a(300);
    REQUIRE(a >= 300);
}

TEST_CASE("Test21") {
    Integer a(100);
    REQUIRE(a != 300);
}

TEST_CASE("Test22") {
    Integer a(100);
    REQUIRE(a == 100);
}

TEST_CASE("Test23") {
    Integer a(100);
    REQUIRE(a == 100);
}

TEST_CASE("Test24") {
    Integer a(0);
    REQUIRE(a == false);
}

TEST_CASE("Test25") {
    Integer a(1);
    REQUIRE(a == true);
}

TEST_CASE("Test26") {
    Integer a(234242432352);
    REQUIRE((bool)a == true);
}

TEST_CASE("Test27") {
    Integer a(97);
    REQUIRE(a == 'a');
}

TEST_CASE("Test28") {
    Integer a(LLONG_MAX);
    REQUIRE(a == LLONG_MAX);
}

TEST_CASE("Test29") {
    Integer a(ULLONG_MAX);
    REQUIRE(a == ULLONG_MAX);
}