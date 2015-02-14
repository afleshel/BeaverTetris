#pragma once

#include "GameBoard.h"
#include "Tetramino.h"
#include "GameStructures.h"
#include "GameEnums.h"
#include <functional>
#include <map>

class AIMovementStrategy
{
public:
	AIMovementStrategy(GameBoard *aGameBoard, Tetramino *aTetramino);
	~AIMovementStrategy(void);

	void updateAI();

private:

	GameBoard *_gameBoard;
	Tetramino *_bossTetramino;
	int _currentUpdateState;
	Tetramino *_lastTetraminoInBossPlace;
	std::map<BossMovementType, std::function<void(GamePositionOnBoard&)> > _bossDirections;

	std::map<BossMovementType, std::function<void(GamePositionOnBoard&)> > getBossDirections();
	GamePositionOnBoard getNewBossPosition();
	void placeBossOnNewPosition(GamePositionOnBoard newBossPosition);
	GamePositionOnBoard getNewBossPositionForDirectionType(BossMovementType aMovementType);
	bool checkPossitionPossibility(GamePositionOnBoard aPossiblePosition);
	bool bossTypeEqualTetraminoType(Tetramino *aTetramino);

};

