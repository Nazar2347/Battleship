#include "ShipRender.h"
#include "VisualConfigs.h"
#include "GameRules.h"

void ShipRender::DrawShips(const std::vector<Ship>& ships)
{
    using namespace VisualConfig;
   
    for (const auto& ship : ships)
    {
     
        for (const Coordinate& coord : ship.getPosition())
        {
            
            DrawRectangle(
                GRID_OFFSET_X + coord.x * CELL_SIZE,
                GRID_OFFSET_Y + coord.y * CELL_SIZE,
                CELL_SIZE,
                CELL_SIZE,
                getShipTypeColor(ship.getShipType())
            );
        }
    }
}

void ShipRender::DrawEnemyShips(const std::vector<Ship>& ships)
{
    using namespace VisualConfig;

    for (const auto& ship : ships)
    {

        for (const Coordinate& coord : ship.getPosition())
        {

            DrawRectangle(
                ENEMY_GRID_OFFSET_X + coord.x * CELL_SIZE,
                ENEMY_GRID_OFFSET_Y + coord.y * CELL_SIZE,
                CELL_SIZE,
                CELL_SIZE,
                getShipTypeColor(ship.getShipType())
            );
        }
    }
}

void ShipRender::drawGhostShip(const Ship& ship, Color color)
{
    using namespace VisualConfig;

    for (const Coordinate& c : ship.getPosition()) {
        DrawRectangle(
            GRID_OFFSET_X + c.x * CELL_SIZE,
            GRID_OFFSET_Y + c.y * CELL_SIZE,
            CELL_SIZE,
            CELL_SIZE,
            Fade(color, 0.5f)
        );
        DrawRectangleLines(
            GRID_OFFSET_X + c.x * CELL_SIZE,
            GRID_OFFSET_Y + c.y * CELL_SIZE,
            CELL_SIZE,
            CELL_SIZE,
            BLACK
        );
    }
}