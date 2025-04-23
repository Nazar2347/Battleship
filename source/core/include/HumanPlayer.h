#pragma once
#include "Player.h"


class HumanPlayer :public Player
{
private:
public:
	HumanPlayer(std::string name);
	void placeShips() override;
	Coordinate getNextMove() override;
};