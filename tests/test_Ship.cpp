#include <catch2/catch_test_macros.hpp>

#include <cstdint>
#include "Ship.h"


TEST_CASE("Ship::IsSunk() works correctly ", "[Ship]")
{

    Ship ship(ShipType::CRUISER, { 0,0 }, Orientation::HORIZONTAL);


    SECTION("Ship is not sunk initially")
    {
        REQUIRE(ship.ISSunk() == false);
    }

    SECTION("Ship is sunk after all parts are hit")
    {
        ship.registerHit({ 0, 0 });
        ship.registerHit({ 1, 0 });
        ship.registerHit({ 2, 0 });
        REQUIRE(ship.ISSunk() == true);
    }

    SECTION("Ship is not sunk if only some parts are hit")
    {
        ship.registerHit({ 0, 0 });
        REQUIRE(ship.ISSunk() == false);
    }
}