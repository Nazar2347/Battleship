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
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && m_board.isValidPlacement(previewShip))
			{
				m_ships.push_back(previewShip);
				m_board.placeShip(previewShip);
				shipIndex++;
			}
		}
		EndDrawing();
	}
}
Coordinate HumanPlayer::getNextMove()
{
	/*Implment RayLib input*/
	return { 0,0 };
}