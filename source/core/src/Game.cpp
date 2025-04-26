#include "Game.h"

Game::Game() :
	m_player("You"), m_aiPlayer("AI"), m_currentState (GameState::INITIALIZATION)
{
	
	m_player.placeShips();
	m_aiPlayer.placeShips();
	

	m_currentState = GameState::PLAYER_TURN;
}
const Board& Game::getEnemyBoard()
{
	return m_aiPlayer.getBoard();
}
const Board& Game::getPlayerBoard()
{
	return m_player.getBoard();
}
HumanPlayer Game::getPlayer()
{
	return m_player;
}
AIPlayer Game::getAIPLayer()
{
	return m_aiPlayer;
}


bool Game::Update()
{
	if (m_currentState == GameState::GAME_OVER)
	{
		return false;
	}
	switch (m_currentState)
	{
	case GameState::INITIALIZATION:
		DrawInitializationMessage();
		break;
	case GameState::PLAYER_TURN:
		ProcessPlayerTurn();
		break;
	case GameState::AI_TURN:
		ProcessAITurn();
		break;
	case GameState::PLAYER_WIN:
		DrawWinMessage();
		break;
	case GameState::ENEMY_WIN:
		DrawLoseMessage();
		break;
	default:

		return false;
		break;
	}
	

}

void Game::ProcessPlayerTurn()
{

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Coordinate shootCoordinate = m_player.getNextMove();

		if (shootCoordinate.x >= 0 && shootCoordinate.y >= 0 && !m_aiPlayer.getBoard().IsAlreadyAttacked(shootCoordinate))
		{
			if (m_aiPlayer.getBoard().recieveAttack(shootCoordinate))
			{
				
			}
			else
			{
				m_currentState = GameState::AI_TURN;
			}
			CheckGameOver();
		}
	}
}

void Game::ProcessAITurn()
{
	Coordinate AIShootCoordinate = m_aiPlayer.getNextMove();

	if (!m_player.getBoard().IsAlreadyAttacked(AIShootCoordinate))
	{
		if (m_player.getBoard().recieveAttack(AIShootCoordinate))
		{
			
		}
		else
		{
			m_currentState = GameState::PLAYER_TURN;
		}
		CheckGameOver();
	}
	
}
void Game::CheckGameOver()
{
	if (m_aiPlayer.getBoard().allShipsSunk())
	{
		m_currentState = GameState::PLAYER_WIN;
	}
	else if (m_player.getBoard().allShipsSunk())
	{
		m_currentState = GameState::ENEMY_WIN;
	}
}