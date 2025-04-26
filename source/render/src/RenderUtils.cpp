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

void DrawHitMark(const Coordinate& coord, Vector2 boardOrigin)
{
    using namespace VisualConfig;
    
    Vector2 cellPos = {
        boardOrigin.x + coord.x * CELL_SIZE,
        boardOrigin.y + coord.y * CELL_SIZE
    };

    float centerX = cellPos.x + CELL_SIZE / 2;
    float centerY = cellPos.y + CELL_SIZE / 2;
    float offset = CELL_SIZE / 4;

    DrawLine(centerX - offset, centerY - offset, centerX + offset, centerY + offset, RED);
    DrawLine(centerX - offset, centerY + offset, centerX + offset, centerY - offset, RED);
}

void DrawMissMark(const Coordinate& coord, Vector2 boardOrigin)
{
    using namespace VisualConfig;
    Vector2 cellPos = {
        boardOrigin.x + coord.x * CELL_SIZE,
        boardOrigin.y + coord.y * CELL_SIZE
    };

    float centerX = cellPos.x + CELL_SIZE / 2;
    float centerY = cellPos.y + CELL_SIZE / 2;

    DrawCircle(centerX, centerY, CELL_SIZE / 6, BLUE);
}