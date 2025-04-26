#include "RenderUtils.h"

bool isMouseOverEnemyBoard(Vector2 mousePos)
{
    using namespace VisualConfig;
    using namespace GameRules;
    return mousePos.x >= ENEMY_GRID_OFFSET_X &&
        mousePos.x < ENEMY_GRID_OFFSET_X + BOARD_SIZE * CELL_SIZE &&
        mousePos.y >= GRID_OFFSET_Y &&
        mousePos.y < GRID_OFFSET_Y + BOARD_SIZE * CELL_SIZE;
}

bool isMouseOverPlayerBoard(Vector2 mousePos)
{
    using namespace VisualConfig;
    using namespace GameRules;
    return mousePos.x >= GRID_OFFSET_X &&
        mousePos.x < GRID_OFFSET_X + BOARD_SIZE * CELL_SIZE &&
        mousePos.y >= GRID_OFFSET_Y &&
        mousePos.y < GRID_OFFSET_Y + BOARD_SIZE * CELL_SIZE;
}