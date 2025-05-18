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

    DrawLine(centerX - offset, centerY - offset, centerX + offset, centerY + offset, BLACK);
    DrawLine(centerX - offset, centerY + offset, centerX + offset, centerY - offset, BLACK);
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
    if (boardOrigin.x == GRID_OFFSET_X &&
        boardOrigin.y == GRID_OFFSET_Y)
    {
        DrawCircle(centerX, centerY, CELL_SIZE / 6, RED); // draw miss mark of an enemy 
    }
    else
    {
        DrawCircle(centerX, centerY, CELL_SIZE / 6, BLUE);
    }
}
void DrawWinMessage()
{
    DrawText("YOU WIN!", 450, 30, 40, GREEN);
 }
void DrawLoseMessage()
{
    DrawText("YOU LOSE!", 450, 30, 40, RED);
}
void DrawInitializationMessage()
{
    DrawText("Place your ships!", 125, 50, 40, BLUE);
   
}
void DrawFightMessage()
{
    DrawText("Fight!", 500, 50, 40, RED);
}
void DrawChangeOrientationMessage()
{
    DrawText("RMB", 550, 200, 20, BLUE);
    DrawText(" - to change ship orientation" , 600,200,20, DARKGRAY);
}