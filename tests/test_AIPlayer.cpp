#include <catch2/catch_test_macros.hpp>
#include "AIPlayer.h"  
#include "GameRules.h"
#include <unordered_set>

TEST_CASE("AI places all ships correctly", "[AIPlayer]") {
    AIPlayer ai("TestAI");

    ai.placeShips();

    const auto& placedShips = ai.getBoard().getShips();

   // Case 1. Correct number of ships placed
    REQUIRE(placedShips.size() == GameRules::shipsToPlace.size());

    //Case 2. No overlapping ships
     std::unordered_set<Coordinate> occupiedCells;
    for (const auto& ship : placedShips)
    {
        for (const auto& pos : ship.getPosition())
        {
           Coordinate cell (pos.x, pos.y);
           REQUIRE(occupiedCells.count(cell) == 0); //case 2  two ships share DO NOT same cell 
            occupiedCells.emplace(cell);
        }
    }

    //Case 3. Ships placed within board boundaries
     
    for (const Ship & ship : placedShips) {
        for (const Coordinate & pos : ship.getPosition()) {
            REQUIRE(pos.x >= 0);
            REQUIRE(pos.x < GameRules::BOARD_SIZE);
            REQUIRE(pos.y >= 0);
            REQUIRE(pos.y < GameRules::BOARD_SIZE);
        }
    }
}