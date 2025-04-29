#include "Board.h"
using namespace std;

Board::Board():
    m_grid(GameRules::BOARD_SIZE, std::vector<CellState>(GameRules::BOARD_SIZE, CellState::EMPTY)) //initialized matrix
{
	cout << "Board initialized!\n";
}

bool Board::isValidPlacement(const Ship& ship) const
{
    for (auto& coord : ship.getPosition()) {
        //Cheking if ship placement is in grid area
        if (coord.x < 0 || coord.x >= GameRules::BOARD_SIZE || coord.y < 0 || coord.y >= GameRules::BOARD_SIZE)
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
    if (coordinates.x  >=0 && coordinates.y >=0 &&
        coordinates.x < GameRules::BOARD_SIZE && coordinates.y < GameRules::BOARD_SIZE)
    {
        #ifdef DEBUG
        cout << "Shoot on [ " << coordinates.x << " " << coordinates.y << "] \n";
        #endif // DEBUG
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
    return false;
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
    m_grid[cooridnates.x][cooridnates.y] = CellState::HIT;

    for (auto& ship : m_ships)
    {
        for (auto i : ship.getPosition())
        {
            if (i == cooridnates)
            {
                ship.registerHit(cooridnates);
                if (ship.ISSunk())
                {
                    m_destroyed_shipsID.emplace(ship.getID(), ship);
                    return;
                }
            }

        }
    }
}
void Board::markMiss(const Coordinate cordinates)
{
    m_grid[cordinates.x][cordinates.y] = CellState::MISS;
    /* Optionaly add visual */
}


bool Board::allShipsSunk() const 
{
    if (m_destroyed_shipsID.size() != GameRules::shipsToPlace.size())
    {
        return false;
    }
#ifdef DEBUG
    cout << "All ships are sunked!\n";
#endif // DEBUG

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

unordered_map<int,Ship> Board::getDestroyedShips()const 
{
    return m_destroyed_shipsID;
}
