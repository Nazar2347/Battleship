#include "Ship.h"
#include <string>
#define DEBUG
using namespace std;

 int Ship::s_nextID = 0;

Ship::Ship(ShipType type, Coordinate placePosittion, Orientation orientation):
	 m_orientation(orientation),m_shipType(type)
{
	m_ID = s_nextID++; 
	m_size = getShipTypeSize(type);
	m_IsHull.resize(m_size, true);
	m_position.clear();

	if (m_orientation == Orientation::HORIZONTAL)
	{
		for (int xPos = 0; xPos < m_size;xPos++)
		{
			m_position.emplace_back( placePosittion.x + xPos, placePosittion.y );
		}
	}
	else // Orientation::VERTICAL
	{
		for (int yPos = 0; yPos < m_size;yPos++)
		{
			m_position.emplace_back ( placePosittion.x, placePosittion.y+yPos );
		}
	}

}

bool Ship::ISSunk()const
{
	int count = m_size;
	for (auto part : m_IsHull)
	{
		if (part == true)
		{
			return false;
		}
	} 
#ifdef DEBUG
	cout << "Ship destroyed!\n";
#endif // DEBUG
	
	return true;
}
size_t Ship::getSize() const
{
	return m_size;
}
int Ship::getID()const
{
	return m_ID;
}

vector<Coordinate> Ship::getPosition() const
{
	return m_position;
}
Orientation Ship::getOrientation()const
{
	return m_orientation;
}
ShipType Ship::getShipType()const
{
	return m_shipType;
}
void Ship::registerHit(Coordinate coordinates)
{
	for (size_t i =0; i<m_position.size();i++)
	{
		if (m_position[i]==coordinates)
		{
			/*Preferably add visual*/
			m_IsHull[i] = false;
          #ifdef DEBUG
			cout << "Hit registred on: (" << coordinates.x << "," << coordinates.y << ")\n";
          #endif // DEBUG

			
			break;
		}
	}
}


