#include <catch_test_macros.hpp>
#include <cstdint>
#include "HumanPlayer.h"


TEST_CASE("HumanPlayer correctly places a ship", "[HumanPlayer]") {
    HumanPlayer player("Test Player");

    Ship testShip(ShipType::DESTROYER, {0,0}, Orientation::HORIZONTAL);

    bool placed = player.tryPlaceShip(testShip);

    REQUIRE(placed == true); 
    REQUIRE(player.getBoard().getShips().size() == 1);
    REQUIRE(player.getBoard().getShips()[0].getPosition() == testShip.getPosition());
}