#include "ShipRender.h"
#include "VisualConfigs.h"
#include "GameRules.h"

std::tuple<int, int, int, int> ShipRender::getObjectOutline(const std::vector<Coordinate>& positions)
{
	int minX = positions[0].x;
	int maxX = positions[0].x;
	int minY = positions[0].y;
	int maxY = positions[0].y;

	for (const Coordinate& coord : positions)
	{
		if (coord.x < minX) minX = coord.x;
		if (coord.x > maxX) maxX = coord.x;
		if (coord.y < minY) minY = coord.y;
		if (coord.y > maxY) maxY = coord.y;
	}

	return { minX, minY, maxX, maxY };
}

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
void ShipRender::DrawDestroyedShips(const Board& playerFleet, const Board& enemyFleet)
{
	using namespace VisualConfig;
	auto drawShip = [=](const Ship& ship, int offsetX, int offsetY, Color fillColor, Color borderColor)
		{
			const auto& positions = ship.getPosition();
			auto [minX, minY, maxX, maxY] = getObjectOutline(positions);

			// Draw ship fill
			for (const Coordinate& coord : positions)
			{
				int x = offsetX + coord.x * CELL_SIZE;
				int y = offsetY + coord.y * CELL_SIZE;
				DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, Fade(fillColor, 0.5f));
			}

			// Draw bounding box
			float rectX = offsetX + minX * CELL_SIZE;
			float rectY = offsetY + minY * CELL_SIZE;
			float rectWidth = (maxX - minX + 1) * CELL_SIZE;
			float rectHeight = (maxY - minY + 1) * CELL_SIZE;

			
			DrawRectangleRoundedLinesEx({ rectX, rectY, rectWidth, rectHeight }, 1.0f, 20.0f, 2.0f, borderColor);
		};

	// Player destroyed ships (BLACK fill, DARKGRAY border)
	for (const auto& pair : playerFleet.getDestroyedShips())
		drawShip(pair.second, GRID_OFFSET_X, GRID_OFFSET_Y, BLACK, BLACK);

	// Enemy destroyed ships (GREEN fill, DARKGREEN border)
	for (const auto& pair : enemyFleet.getDestroyedShips())
		drawShip(pair.second, ENEMY_GRID_OFFSET_X, ENEMY_GRID_OFFSET_Y, Fade(DARKGREEN, 0.5f), DARKGREEN);
	


	
}