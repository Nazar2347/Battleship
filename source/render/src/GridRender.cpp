#include "GridRender.h"
#include "VisualConfigs.h"
#include "GameRules.h"

void GridRender::drawGrid()
{
	using namespace VisualConfig;

	for (int y = 0; y <= GameRules::BOARD_SIZE; y++)
	{
		DrawLine(
			GRID_OFFSET_X,
			GRID_OFFSET_Y + y * CELL_SIZE,
			GRID_OFFSET_X + GameRules::BOARD_SIZE * CELL_SIZE,
			GRID_OFFSET_Y + y * CELL_SIZE,
			GRAY
		);
	}

	for (int x = 0; x <= GameRules::BOARD_SIZE; ++x) 
	{
		DrawLine(
			GRID_OFFSET_X + x * CELL_SIZE,
			GRID_OFFSET_Y,
			GRID_OFFSET_X + x * CELL_SIZE,
			GRID_OFFSET_Y + GameRules::BOARD_SIZE * CELL_SIZE,
			GRAY
		);
	}
}