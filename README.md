# Battleship Game (C++ / Raylib)
A mine representaion on the classic Battleship game, built in C++ with Raylib for rendering and CMake for build automation.
Includes core game logic, interactive UI, and robust unit tests using Catch2

# Features
- 🎮 Two-player turn-based gameplay: Human vs AI
- 🤖 AI ship placement and attack using randomization
- 🟢 Rendering, UI, visuals (hits,misses, destroyed ships) with Raylib
- 🧪 Unit tests with Catch2
- 🧱 Modular OOP structure: Board, Player, Ship, Renderer, GameRules
- 📁 Clean folder structure and CMake build automation
  
## How to run the game
To Play the game you can simply open: 
MainExecutable.exe in : Battleship\install\bin\MainExecutable.exe

Or you can install on your computer using: 
BattleShip-0.1.1-win64.exe 
##
## How to run the tests 🧪
1. Clone repository, open command console in downloaded repo
2. Run these commands: 
 - cmake -S . -B ./build
 - cmake --build ./build
 - ctests --test-dir ./build/tests --verbose
 ### OR 
You can see tests are always running after succesfull build and compilation of the program! 
##
It's my third small game project, where this time I used newly obtained skills such as:
- Raylib:	Rendering and UI
- Catch2:	Unit testing
- CMake:	Build system(Windows)
- Git:	Version control
