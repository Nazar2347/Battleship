#pragma once

struct Coordinate
{
	int x;
	int y;

	Coordinate(int x, int y) : x(x), y(y) {}

	// Comparison operator 
	bool operator==(const Coordinate& other) const {
		return x == other.x && y == other.y;
	}
};