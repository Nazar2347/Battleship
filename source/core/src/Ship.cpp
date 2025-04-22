#include "Ship.h"
#include <string>

using namespace std;

Ship::Ship(ShipType type, vector<Coordinate> coordinates, Orientation orientation):
	m_position(coordinates), m_orientation(orientation)
{
	m_size = getShipTypeSize(type);

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
			m_IsHull[i] == true;
			cout << "Hit registred on: (" << coordinates.x << "," << coordinates.y << "\n";
			break;
		}
	}
}


