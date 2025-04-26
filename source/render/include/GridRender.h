#pragma once
#include <raylib.h>
#include "RenderUtils.h"
#include "Board.h"

class GridRender
{
public:
	void drawPlayerGrid();
	void drawEnemyGrid();
	void displayPlayerCellStates(Board board);
	void displayEnemyCellStates(Board board);
};