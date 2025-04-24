#include "AIPlayer.h"
#include <ctime>
#include <unordered_set>

using namespace std;

AIPlayer::AIPlayer(string name) :
	Player(name),
	randomNumberGenerator(static_cast<unsigned int>(std::time(nullptr))),
	m_coordDist(0, GameRules::BOARD_SIZE - 1) //defining range for number generator
{
}

Orientation AIPlayer::horizontalOrVertical()
{
	bool horizontalOrVertical = m_coordDist(randomNumberGenerator) % 2 == 0;
	if (horizontalOrVertical == 0)
	{
		return Orientation::HORIZONTAL;
	}
	else
	{
		return Orientation::VERTICAL;
	}
}

void AIPlayer::placeShips()
{
	m_ships.clear();
	/*required to refactor this method to make it more efficient template for creating different types of ships for the board*/
		//Creating ships and placing them on board
	using namespace GameRules;
	for (int frigates = 4; frigates > 0; frigates--)
	{
		bool isPlaced = false;
		while (!isPlaced)
		{

			Ship frigate(ShipType::FRIGATE, generateRandomCoordinate(), horizontalOrVertical());
			if (m_board.isValidPlacement(frigate))
			{
				m_ships.push_back(frigate);
				m_board.placeShip(frigate);
				isPlaced = true;
			}
		}

	}
	for (int destroyer = 3; destroyer > 0;destroyer--)
	{
		bool isPlaced = false;
		while (!isPlaced)
		{

			Ship frigate(ShipType::DESTROYER, generateRandomCoordinate(), horizontalOrVertical());
			if (m_board.isValidPlacement(frigate))
			{
				m_ships.push_back(frigate);
				m_board.placeShip(frigate);
				isPlaced = true;
			}
		}
	}
	for (int cruisers = 2; cruisers > 0;cruisers--)
	{
		bool isPlaced = false;
		while (!isPlaced)
		{

			Ship cruiser(ShipType::CRUISER, generateRandomCoordinate(), horizontalOrVertical());
			if (m_board.isValidPlacement(cruiser))
			{
				m_ships.push_back(cruiser);
				m_board.placeShip(cruiser);
				isPlaced = true;
			}
		}
	}
	for (int linkors = 1; linkors > 0; linkors)
	{
		bool isPlaced = false;
		while (!isPlaced)
		{

			Ship linkor(ShipType::CRUISER, generateRandomCoordinate(), horizontalOrVertical());
			if (m_board.isValidPlacement(linkor))
			{
				m_ships.push_back(linkor);
				m_board.placeShip(linkor);
				isPlaced = true;
			}
		}
	}



}

Coordinate AIPlayer::getNextMove()
{
	return Coordinate(m_coordDist(randomNumberGenerator), m_coordDist(randomNumberGenerator));
}

Coordinate AIPlayer::generateRandomCoordinate()
{
	return Coordinate(m_coordDist(randomNumberGenerator), m_coordDist(randomNumberGenerator));
}