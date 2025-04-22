#pragma once
#include <iostream>
#include <vector>

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
		break;
	}
}

class Ship
{
private:
	size_t m_size;
	std::vector<std::pair<int, int >> m_position;
	Orientation m_orientation;
	std::vector<bool> m_IsHull;
protected:
public:
	Ship(ShipType type, std::pair<int, int> coordinates, Orientation orientation);
	virtual bool ISSunk()const;
	size_t getSize()const;
	std::vector<std::pair<int,int>>getPosition()const;
	Orientation getOrientation()const;

	void registerHit(std::pair<int, int> coorinates);
	

	virtual ~Ship();

};