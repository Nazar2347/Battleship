#include "ShipRender.h"
#include "VisualConfigs.h"
#include "GameRules.h"

void ShipRender::DrawShips(const std::vector<Ship>& ships)
{
    using namespace VisualConfig;
   
    for (const auto& ship : ships)
    {
        ship.getSize();
        auto x = DARKGRAY;
        switch (ship.getSize())
        {
        case 1: 
            x = LIGHTGRAY;
            break;
        case 2:
            x = DARKBLUE;
            break;
        case 3:
            x = DARKGREEN;
            break;
        case 4:
            x = DARKPURPLE;
        default:
            x = BLACK;
            break;
        }


        for (const Coordinate& coord : ship.getPosition())
        {
            
            DrawRectangle(
                BOARD_OFFSET_X + coord.x * CELL_SIZE,
                BOARD_OFFSET_Y + coord.y * CELL_SIZE,
                CELL_SIZE,
                CELL_SIZE,
                x
            );
        }
    }
}