/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Example complexity rating: [★☆☆☆] 1/4
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute 'raylib_compile_execute' script
*   Note that compiled executable is placed in the same folder as .c file
*
*   To test the examples on Web, press F6 and execute 'raylib_compile_execute_web' script
*   Web version of the program is generated in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "GameRules.h"
#include "GridRender.h"
#include "ShipRender.h"
#include "AIPlayer.h"
#include "HumanPlayer.h"
#include "VisualConfigs.h"
#include "Game.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 550;
    using namespace VisualConfig;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);               

    Game game1;
    GridRender board;
    ShipRender vivisbleShips;
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {   
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);
        board.drawPlayerGrid();
        board.drawEnemyGrid();
        game1.Update();
       
        vivisbleShips.DrawShips(game1.getPlayerBoard().getShips());
        vivisbleShips.DrawDestroyedShips(game1.getPlayerBoard(), game1.getEnemyBoard()); //Draw  Destroyed ships 
 
        board.displayEnemyCellStates(game1.getAIPLayer().getBoard());
        board.displayPlayerCellStates(game1.getPlayer().getBoard());

       
        
        
       
    

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
