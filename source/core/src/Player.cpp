#include "Player.h"

using namespace std;

Player::Player(string name) :
	m_name(name) 
{
	m_board = Board();
}

bool Player::AtackOnEnemyBoard(const Coordinate target)
{
	return m_board.recieveAttack(target);
}

bool Player::hasLost()const
{
	if (m_board.allShipsSunk())
	{
		return true;
	}
	return false;
}

const Board& Player::getBoard()const
{
	return m_board;
}

string Player::getName()const
{
	return m_name;
}

Board& Player::getBoard()
{
	return m_board;
}