#pragma once

#include "GameSystemInterface.h"
#include "ServiceInterface.h"

class GameBoard;
class GameTimeStepController;
class VictoryConditionInterface;
class GameResultDelegate;

class WinGameSystem :public GameSystemInterface, public ServiceInterface
{
public:
	WinGameSystem();
	~WinGameSystem(void);

	void updateSystem(float deltaTime);
	bool gameEnded();
	bool playerWin();

private:

	GameBoard *_gameBoard;
	GameTimeStepController *_gameTimeStepController;
	VictoryConditionInterface *_currentVictoryCondition;
	GameResultDelegate *_gameResultDelegate;
	bool _gameEnded;
	bool _playerWin;

	void checkWinGameState();
	void checkLoseGameState();
	bool loseGameChecker();

};

