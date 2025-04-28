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
//Hash function for coordinates for unordored_set
namespace std
{
	template<>
	struct hash<Coordinate> {
		std::size_t operator()(const Coordinate& coord) const {
			return std::hash<int>()(coord.x) ^ (std::hash<int>()(coord.y) << 1);
		}
	};
}