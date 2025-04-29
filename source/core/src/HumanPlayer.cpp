#include "HumanPlayer.h"
using namespace std;

HumanPlayer::HumanPlayer(string name) :
	Player(name)
{
};

void HumanPlayer::placeShips()
{
	using namespace VisualConfig;
	m_ships.clear();
	
	Orientation currentOrientation = Orientation::HORIZONTAL;

	size_t shipIndex = 0;
	GridRender tempBoard;
	ShipRender ghostShip;
	ShipRender placedShips;

	while (shipIndex < GameRules::shipsToPlace.size() && !WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawInitializationMessage();
		DrawChangeOrientationMessage();

		tempBoard.drawPlayerGrid();
		placedShips.DrawShips(m_board.getShips());

		Vector2 mouse = GetMousePosition();

		if (isMouseOverPlayerBoard(mouse))
		{
		int x = static_cast<int>((mouse.x - GRID_OFFSET_X) / CELL_SIZE);
		int y = static_cast<int>((mouse.y - GRID_OFFSET_Y) / CELL_SIZE);
			Coordinate coord = { x,y };

			Ship previewShip(GameRules::shipsToPlace[shipIndex], coord, currentOrientation);
			//Showing ghost ship
			if (m_board.isValidPlacement(previewShip))
			{
				ghostShip.drawGhostShip(previewShip, GREEN);
			}
			else
			{
				ghostShip.drawGhostShip(previewShip, RED);
			}


			//Rotate
			if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON))
			{
				currentOrientation = (currentOrientation == Orientation::HORIZONTAL) ?
					Orientation::VERTICAL : Orientation::HORIZONTAL;
			}
			//Place
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && tryPlaceShip(previewShip))
			{
				shipIndex++;
			}
		}
		EndDrawing();
	}
}
Coordinate HumanPlayer::getNextMove()
{
	using namespace VisualConfig;
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();

		if (isMouseOverEnemyBoard(mousePos))
		{

			int cellX = static_cast<int>((mousePos.x - (ENEMY_GRID_OFFSET_X)) / CELL_SIZE);
			int cellY = static_cast<int>((mousePos.y - ENEMY_GRID_OFFSET_Y) / CELL_SIZE);

			if (cellX >= 0 && cellX < 10 && cellY >= 0 && cellY < 10)
			{
				return Coordinate{ cellX, cellY };
			}
		}
	}

	return { -1,-1 };
}