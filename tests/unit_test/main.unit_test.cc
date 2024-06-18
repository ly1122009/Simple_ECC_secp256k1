#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "func.hpp"


TEST_CASE("Test sum funcion", "[cal_sum]")
{
    REQUIRE(cal_sum(1,2) == 3);
    REQUIRE(cal_sum(2,2) == 4);
    REQUIRE(cal_sum(5,2) == 7);
    REQUIRE(cal_sum(22,2) == 24);
}
