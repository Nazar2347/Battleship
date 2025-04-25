#pragma once 
#include "Ship.h"
#include <raylib.h>

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
public:
    void DrawShips(const std::vector<Ship>& ships);
    void drawGhostShip(const Ship& ship, Color color);
};