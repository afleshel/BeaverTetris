#pragma once

#include <vector>
#include "GameStructures.h"

class ExplosionAnimationDelegate;
class CurrentPlayerDataSource;
class GameBoard;

class TetraminosChainCleaner
{
public:
	TetraminosChainCleaner(GameBoard *aGameBoard);
	~TetraminosChainCleaner(void);

	void cleanChain(std::vector<GamePositionOnBoard> aPositions);
	void setDelegate(ExplosionAnimationDelegate *aDelegate);

private:

	ExplosionAnimationDelegate *_delegate;
	CurrentPlayerDataSource *_currentPlayerDataSource;
	GameBoard *_gameBoard;
	int _prizeForChainConstant;

	void setAwardToPlayerFromTetraminos(std::vector<GamePositionOnBoard> aTetraminos);
	void addAwardToPlayer(int awardForChain);
	int getAwardForChainForTetraminos(std::vector<GamePositionOnBoard> aTetraminos);
	void removeTetraminosWithPositions(std::vector<GamePositionOnBoard> aTetraminos);
	
	void sendMassageToDelegateWithTetraminos(std::vector<GamePositionOnBoard> aTetraminos);
	void sendRemoveTetraminosMassagesToDelegate(std::vector<GamePositionOnBoard> aTetraminos);
	void sendCallbackWithAwardForTetraminosToDelegate(std::vector<GamePositionOnBoard> aTetraminos);

};

