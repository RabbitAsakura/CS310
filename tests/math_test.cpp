#include <catch2/catch.hpp>
#include "math_functions.h"

TEST_CASE("Square root of positive number", "[math]") {
    REQUIRE(compute_sqr_root(25.0) == Approx(5.0));
    REQUIRE(compute_sqr_root(0.0) == Approx(0.0));
}

TEST_CASE("Square root of negative number", "[math]") {
    REQUIRE(compute_sqr_root(-1.0) == -1);
}