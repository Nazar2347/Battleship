#include "GridRender.h"
#include "VisualConfigs.h"
#include "GameRules.h"

void GridRender::drawPlayerGrid()
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

	for (int x = 0; x <= GameRules::BOARD_SIZE; x++) 
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

void GridRender::drawEnemyGrid()
{
	using namespace VisualConfig;

	for (int y = 0; y <= GameRules::BOARD_SIZE; y++)
	{
		DrawLine(
			GRID_OFFSET_X+ ENEMY_GRID_GAP,
			GRID_OFFSET_Y + y * CELL_SIZE,
			GRID_OFFSET_X + GameRules::BOARD_SIZE * CELL_SIZE +ENEMY_GRID_GAP,
			GRID_OFFSET_Y + y * CELL_SIZE,
			DARKGREEN
		);
	}

	for (int x = 0; x <= GameRules::BOARD_SIZE; x++)
	{
		DrawLine(
			GRID_OFFSET_X + x * CELL_SIZE+ENEMY_GRID_GAP,
			GRID_OFFSET_Y,
			GRID_OFFSET_X + x * CELL_SIZE +ENEMY_GRID_GAP,
			GRID_OFFSET_Y + GameRules::BOARD_SIZE * CELL_SIZE,
			DARKGREEN

		);
	}
}

void GridRender::displayPlayerCellStates(Board board)
{

	using namespace GameRules;
	using namespace VisualConfig;
	Vector2 board_origin = { GRID_OFFSET_X, GRID_OFFSET_Y };
	for (int y = 0; y < BOARD_SIZE; y++)
	{
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			if (board.getCellState({ x,y }) == CellState::EMPTY)
			{
				// empty
			}
			else if (board.getCellState({ x,y }) == CellState::HIT)
			{
				DrawHitMark({ x,y }, board_origin);
			}
			else if (board.getCellState({ x,y }) == CellState::MISS)
			{
				DrawMissMark({ x,y }, board_origin);
			}
		}
	}
}
void GridRender::displayEnemyCellStates(Board board)
{
	using namespace GameRules;
	using namespace VisualConfig;
	Vector2 board_origin = { ENEMY_GRID_OFFSET_X, ENEMY_GRID_OFFSET_Y };
	for (int y = 0; y < BOARD_SIZE; y++)
	{
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			if (board.getCellState({ x,y }) == CellState::EMPTY)
			{
				// empty
			}
			else if (board.getCellState({ x,y }) == CellState::HIT)
			{
				DrawHitMark({ x,y }, board_origin);
			}
			else if (board.getCellState({ x,y }) == CellState::MISS)
			{
				DrawMissMark({ x,y }, board_origin);
			}
		}
	}

}