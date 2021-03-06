#include "BossWithOneTetraminoDelegate.h"
#include "Tetramino.h"
#include "ServiceLocator.h"
#include "GameServicesKeys.h"
#include "GameBoard.h"
#include "GameDesignConstants.h"
#include "KeysForEnumsDataSource.h"

using namespace std;

BossWithOneTetraminoDelegate::BossWithOneTetraminoDelegate(Tetramino *aTetramino)
{
	_bossTetramino = aTetramino;

	GameBoard *gameBoard = (GameBoard*)ServiceLocator::getServiceForKey(gameBoardKey);
	gameBoard->replaceTetraminoXYposition(_bossTetramino,((tetrisBlocksWidth / 2) - 1), (standartDetailHeight/2));
	
	KeysForEnumsDataSource *keysForEnumsDataSource = (KeysForEnumsDataSource*)ServiceLocator::getServiceForKey(keysForEnumsDataSourceKey);
	_bossKey = keysForEnumsDataSource->getKeyForTetraminoType(aTetramino->getTetraminoType());
}


BossWithOneTetraminoDelegate::~BossWithOneTetraminoDelegate(void)
{
}


int BossWithOneTetraminoDelegate::getVictoryStateInformationCount(void)
{
	return 1;
}

int BossWithOneTetraminoDelegate::getVictoryStateInformationForIndex(int aIndex)
{
	int stateInformation = 0;
	if (_bossTetramino != NULL)
	{
		stateInformation = getBossStateInformation();
	}
	return stateInformation;
}

int BossWithOneTetraminoDelegate::getBossStateInformation()
{
	int bossStateInformation = _bossTetramino->getTetraminoLivesCount();
	if (bossStateInformation < 0)
	{
		bossStateInformation = 0;
	}
	return bossStateInformation;
}

string BossWithOneTetraminoDelegate::getVictoryStateIconImageForIndex(int aIndex)
{
	return _bossKey;
}

bool BossWithOneTetraminoDelegate::playerWin(void)
{
	bool win = true;
	if (_bossTetramino != NULL)
	{
		win = getBossWin();
	}
	return win;
}

bool BossWithOneTetraminoDelegate::getBossWin()
{
	bool winBoss = true;
	if (_bossTetramino->getTetraminoLivesCount() > 0)
	{
		winBoss = false;
	}
	return winBoss;
}

void BossWithOneTetraminoDelegate::tetraminoRemoving()
{
	_bossTetramino = NULL;
}