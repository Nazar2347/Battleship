#include <catch_test_macros.hpp>

#include <cstdint>


TEST_CASE("First Test case ", "[setup]")
{
    SECTION("Test1: ")
    {
        REQUIRE(1 + 1 == 2);
    }
    SECTION("Test2: ")
    {
        REQUIRE(4 + 4 == 8);
    }
}