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
	using namespace GameRules;

	for (auto ship: GameRules::shipsToPlace)
	{
		bool isPlaced = false;
		while (!isPlaced)
		{

			Ship AIShip(ship, generateRandomCoordinate(), horizontalOrVertical());			
			if (tryPlaceShip(AIShip))
			{
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