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
	static int s_nextID;
	int m_ID;
	size_t m_size;
	std::vector<Coordinate> m_position;
	Orientation m_orientation;
	std::vector<bool> m_IsHull;
	ShipType m_shipType;
protected:
public:
	Ship(ShipType type, Coordinate placePosition, Orientation orientation);
	virtual bool ISSunk()const;
	size_t getSize()const;
	int getID()const;
	std::vector<Coordinate>getPosition()const;
	Orientation getOrientation()const;
	ShipType getShipType()const;

	void registerHit(Coordinate coorinates);
	virtual ~Ship() {};

};