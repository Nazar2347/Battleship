#pragma once

namespace VisualConfig
{
	inline constexpr int CELL_SIZE = 40;
	inline constexpr int GRID_OFFSET_X = 100;
	inline constexpr int GRID_OFFSET_Y = 100;
	inline constexpr int GRID_LINE_THICKNESS = 2;
	inline constexpr int GRID_LINE_COLOR = 0xAAAAAAFF; // gray
	inline constexpr int ENEMY_GRID_GAP = 500; //100px gap between boards
	inline constexpr int ENEMY_GRID_OFFSET_X = ENEMY_GRID_GAP + GRID_OFFSET_X;
	inline constexpr int ENEMY_GRID_OFFSET_Y = GRID_OFFSET_Y;
}