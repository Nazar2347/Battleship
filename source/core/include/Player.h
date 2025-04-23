#pragma once
#include "Board.h"
#include "Coordinate.h"
#include "Ship.h"


class Player
{
private:
	std::string m_name;
protected:
	Board m_board;
	std::vector<Ship> m_ships;
public:
	Player(std::string name);

	bool AtackOnEnemyBoard(const Coordinate target);
	bool hasLost()const;

	const Board& getBoard()const;
	std::string getName()const;

	Board& getBoard();

	virtual ~Player();

};
