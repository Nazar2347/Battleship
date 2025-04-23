#pragma once 
#include <iostream>
#include <vector>
#include "Ship.h"
#include "Coordinate.h"
enum class CellState
{
	EMPTY,
	SHIP,
	HIT,
	MISS
};




class Board
{
private:
	std::vector<std::vector<CellState>> m_grid;
	std::vector<Ship> m_ships;

public:
	static const int BOARD_SIZE = 10;

	Board();

	bool placeShip(const Ship& ship);
	bool isValidPlacement(const Ship& ship) const;

	bool recieveAttack(const Coordinate coordinates);
	bool IsAlreadyAttacked(const Coordinate coordinates);

	void markHit(const Coordinate coordinates);
	void markMiss(const Coordinate coordinates);

	const std::vector<Ship>& getShips() const;
	bool allShipsSunk() const;
	CellState getCellState(Coordinate coordinates);


};