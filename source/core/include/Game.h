#pragma once
#include "Board.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

enum class GameState
{
	INITIALIZATION,
	PLAYER_TURN,
	AI_TURN,
	GAME_OVER,
	PLAYER_WIN,
	ENEMY_WIN

};

class Game
{
private:
	HumanPlayer m_player;
	AIPlayer m_aiPlayer;
	GameState m_currentState;

public:
	Game();
	bool Update();
	void ProcessPlayerTurn();
	void ProcessAITurn();
	void CheckGameOver();
	const Board& getEnemyBoard();
	const Board& getPlayerBoard();
	HumanPlayer getPlayer();
	AIPlayer getAIPLayer();

};