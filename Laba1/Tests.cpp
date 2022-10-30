#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Integer.h"

using namespace arbitary_precision_arithmetic;

TEST_CASE("Calc test", "[calculator]") {
    REQUIRE(Integer(6) * Integer(5) == 30);
}