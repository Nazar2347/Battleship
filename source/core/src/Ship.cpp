#include "Ship.h"
#include <string>

using namespace std;

Ship::Ship(ShipType type, Coordinate placePosittion, Orientation orientation):
	 m_orientation(orientation)
{
	m_size = getShipTypeSize(type);
	m_position.reserve(m_size);
	m_IsHull.reserve(m_size, false);

	if (m_orientation == Orientation::HORIZONTAL)
	{
		for (int xPos = 0; xPos < m_size;xPos++)
		{
			m_position[xPos] = { placePosittion.x + xPos,placePosittion.y };
		}
	}
	else // Orientation::VERTICAL
	{
		for (int yPos = 0; yPos < m_size;yPos++)
		{
			m_position[yPos] = { placePosittion.x,placePosittion.y+yPos };
		}
	}

}

bool Ship::ISSunk()const
{
	int count = m_size;
	for (auto i : m_IsHull)
	{
		if (i == 0) count--;
	}
	if (count == 0) 
		return true;
	else 
		return false;
}
size_t Ship::getSize() const
{
	return m_size;
}

vector<Coordinate> Ship::getPosition() const
{
	return m_position;
}
Orientation Ship::getOrientation()const
{
	return m_orientation;
}
void Ship::registerHit(Coordinate coordinates)
{
	for (size_t i =0; i<m_position.size();i++)
	{
		if (m_position[i]==coordinates)
		{
			/*Preferably add visual*/
			m_IsHull[i] = true;
			cout << "Hit registred on: (" << coordinates.x << "," << coordinates.y << "\n";
			break;
		}
	}
}


