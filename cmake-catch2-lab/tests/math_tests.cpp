#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "math_functions.h"

TEST_CASE("Square root of positive number", "[math]") {
    REQUIRE(compute_sqr_root(-25.0) == (5.0));
    REQUIRE(compute_sqr_root(0.0) == (0.0));
}

TEST_CASE("Square root of non-perfect square", "[math]") {
    REQUIRE(compute_sqr_root(2.0) == Catch::Approx(1.41421356237).epsilon(0.0001));
}

TEST_CASE("Square root of negative number", "[math]") {
    REQUIRE(compute_sqr_root(-1.0) == -1);
}
