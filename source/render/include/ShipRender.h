#pragma once 
#include "Board.h"
#include <raylib.h>
#include "RenderUtils.h"
#include <tuple>

inline Color getShipTypeColor(ShipType shipType)
{
	switch (shipType)
	{
	case ShipType::FRIGATE:
		return DARKGRAY;
	case ShipType::DESTROYER:
		return DARKBLUE;
	case ShipType::CRUISER:
		return RED;
	case ShipType::LINKOR:
		return DARKPURPLE;
	default:
		return DARKGRAY;
	}
}


class ShipRender
{
private:
	std::tuple<int,int,int,int> getObjectOutline(const std::vector<Coordinate>& position);
public:
    void DrawShips(const std::vector<Ship>& ships);
    void drawGhostShip(const Ship& ship, Color color);
	void DrawEnemyShips(const std::vector<Ship>& ships);
	void DrawDestroyedShips(const Board& PlayerFleet, const Board& EnemyFleet);
};