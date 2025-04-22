#pragma once
#include <iostream>
#include <vector>
#include "Coordinate.h"


enum class Orientation
{
	HORIZONTAL,
	VERTICAL
};
enum class ShipType
{
	FRIGATE,
	DESTROYER,
	CRUISER,
	LINKOR
};

inline size_t getShipTypeSize(ShipType type)
{
	switch (type)
	{
	case ShipType::FRIGATE: return 1;
		break;
	case ShipType::DESTROYER: return 2;
		break;
	case ShipType::CRUISER: return 3;
		break;
	case ShipType::LINKOR: return 4;
		break;
	default:
		return 0;
		break;
	}
}

class Ship
{
private:
	size_t m_size;
	std::vector<Coordinate> m_position;
	Orientation m_orientation;
	std::vector<bool> m_IsHull;
protected:
public:
	Ship(ShipType type, std::vector<Coordinate>, Orientation orientation);
	virtual bool ISSunk()const;
	size_t getSize()const;
	std::vector<Coordinate>getPosition()const;
	Orientation getOrientation()const;

	void registerHit(Coordinate coorinates);
	virtual ~Ship() {};

};