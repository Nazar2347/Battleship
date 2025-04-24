#pragma once
#include "Player.h"

#include <random> //For random generation

class AIPlayer :public Player
{
private:
	std::mt19937 randomNumberGenerator; // Mersenne Twister pseudo-random number generator
	std::uniform_int_distribution<int> m_coordDist; //Range for random numbers

	Coordinate generateRandomCoordinate();
public:
	AIPlayer(std::string name);
	void placeShips()override;
	Coordinate getNextMove()override;

	Orientation horizontalOrVertical();
};