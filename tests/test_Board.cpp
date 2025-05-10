
#include <catch2/catch_test_macros.hpp>
#include "Board.h"
#include "Ship.h"

TEST_CASE("Board::recieveAttack() works correctly", "[Board]")
{
    Board board;

    // Creates and place a ship manually
    Ship ship(ShipType::FRIGATE, {2,3}, Orientation::HORIZONTAL); // FRIGATE = 1 cell
    REQUIRE(board.placeShip(ship)); // Make sure placement succeeded

    SECTION("Attack on ship should be a hit")
    {
        Coordinate attackCoord{ 2, 3 };
        bool result = board.recieveAttack(attackCoord);

        REQUIRE(result == true); // Should register as a hit
    }

    SECTION("Attack on empty cell should be a miss")
    {
        Coordinate attackCoord{ 5, 5 }; // No ship here
        bool result = board.recieveAttack(attackCoord);

        REQUIRE(result == false); // Should register as a miss
    }

    SECTION("Attack out of bounds should return false")
    {
        Coordinate attackCoord{ -1, 15 }; // Outside the board
        bool result = board.recieveAttack(attackCoord);

        REQUIRE(result == false); // Invalid attack
    }
}

TEST_CASE("Board::markHit() correctly registers a hit", "[Board]")
{
    Board board;

    // Create a ship at known location
    Ship ship(ShipType::FRIGATE, { 1,1 }, Orientation::HORIZONTAL);
    REQUIRE(board.placeShip(ship));

    SECTION("After markHit, cell should be HIT and ship part should be damaged")
    {
        Coordinate hitCoord{ 1, 1 };

        // Ensure cell initially is SHIP
        REQUIRE(board.getCellState(hitCoord) == CellState::SHIP);

        // Act
        board.markHit(hitCoord);

        // Assert
        REQUIRE(board.getCellState(hitCoord) == CellState::HIT); // Cell should now be HIT

        // Optionally check that ship hull is damaged
        const auto& ships = board.getShips();
        REQUIRE(ships.size() == 1);



        // Ship must register hit on that part
        const auto& ship = ships.front();
        bool partHit = false;
        for (size_t i = 0; i < ship.getPosition().size(); ++i)
        {
            if (ship.getPosition()[i] == hitCoord)
            {
                partHit = true;
                break;
            }
        }
        REQUIRE(partHit == true);

        // And if FRIGATE (size 1), it should now be sunk
        REQUIRE(ship.ISSunk() == true);
    }
}
