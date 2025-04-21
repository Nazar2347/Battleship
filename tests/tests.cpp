#include <C:\Users\ndunas\source\repos\Battleship\external\Catch2\src\catch2\catch_test_macros.hpp>
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