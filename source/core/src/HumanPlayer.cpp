#include "HumanPlayer.h"
using namespace std;

HumanPlayer::HumanPlayer(string name) :
	Player(name)
{
};

void HumanPlayer::placeShips()
{
	m_ships.push_back(Ship(ShipType::FRIGATE, { 5,5 }, Orientation::HORIZONTAL));
	m_ships.push_back(Ship(ShipType::FRIGATE, { 1,2 }, Orientation::HORIZONTAL));
	/*Consider to transfer creation logic later*/

	for (auto i : m_ships)
	{
		m_board.placeShip(i);
	}
}
Coordinate HumanPlayer::getNextMove()
{
	/*Implment RayLib input*/
	return { 0,0 };
}