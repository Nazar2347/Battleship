#pragma once
#include "Player.h"
#include "VisualConfigs.h"
#include "GridRender.h"
#include "ShipRender.h"


class HumanPlayer :public Player
{
private:
public:
	HumanPlayer(std::string name);
	void placeShips() override;
	Coordinate getNextMove() override;
};