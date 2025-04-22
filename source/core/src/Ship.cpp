#include "Ship.h"

using namespace std;

Ship::Ship(ShipType type, vector<pair<int, int>> coordinates, Orientation orientation):
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

vector<pair<int, int>> Ship::getPosition() const
{
	return m_position;
}
Orientation Ship::getOrientation()const
{
	return m_orientation;
}
void Ship::registerHit(pair<int, int> coordinates)
{
	for (auto i : m_position)
	{
		if (i.first == coordinates.first && i.second == coordinates.second)
		{
			cout << "Recieved hit!";
			/*Require to redifine logic!*/
			for (auto i : m_IsHull)
			{
				if (i != 0)
				{
					i = 0;
				}
			}
		}
	}
}


