#include "Board.h"
using namespace std;

Board::Board():m_grid(BOARD_SIZE, std::vector<CellState>(BOARD_SIZE, CellState::EMPTY))
{
	cout << "Board initialized!\n";
}

bool Board::isValidPlacement(const Ship& ship) const
{
    for (auto& coord : ship.getPosition()) {
        //Cheking if ship placement is in grid area
        if (coord.x < 0 || coord.x >= BOARD_SIZE || coord.y < 0 || coord.y >= BOARD_SIZE)
            return false; 
        //Cheking if ship placement cell is Empty
        if (m_grid[coord.x][coord.y] != CellState::EMPTY)
            return false;
    }
    return true;
}

bool Board::placeShip(const Ship& ship)
{
    if (!isValidPlacement(ship))
    {
        return false;
    }
    for (auto coord : ship.getPosition())
    {
        m_grid[coord.x][coord.y] = CellState::SHIP;
    }
    m_ships.push_back(ship);
    return true;
}

bool Board::recieveAttack(const Coordinate coordinates)
{
    if (m_grid[coordinates.x][coordinates.y] == CellState::SHIP)
    {
        markHit(coordinates);
        return true;
    }
    else
    {
        markMiss(coordinates);
        return false;
    }
}

bool Board::IsAlreadyAttacked(const Coordinate coordinates)
{
    if (m_grid[coordinates.x][coordinates.y] == CellState::HIT)
    {
        return true;
    }
    else if (m_grid[coordinates.x][coordinates.y] == CellState::MISS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Board::markHit(const Coordinate cooridnates)
{
    m_grid[cooridnates.x][cooridnates.y] == CellState::HIT;

    for (auto ship : m_ships)
    {
        for (auto i : ship.getPosition())
        {
            if (i == cooridnates)
            {
                ship.registerHit(cooridnates);
                return;
            }
    
        }
    }
}
void Board::markMiss(const Coordinate cordinates)
{
    m_grid[cordinates.x][cordinates.y] = CellState::MISS;
    /* Optionaly add visual */
}


bool Board::allShipsSunk() const {
    for (const auto& ship : m_ships) 
    {
        if (!ship.ISSunk())
            return false;
    }
    return true;
}

const vector<Ship>& Board::getShips()const
{
    return m_ships;
}
CellState Board::getCellState(Coordinate coordinates)
{
    return m_grid[coordinates.x][coordinates.y];
}