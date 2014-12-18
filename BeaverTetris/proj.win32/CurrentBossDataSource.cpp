#include "CurrentBossDataSource.h"

using namespace std;

CurrentBossDataSource::CurrentBossDataSource(CurrentLevelDataSource *aCurrentLevelDataSource, GameBoard *aGameBoard)
{
	_currentLevelDataSource = aCurrentLevelDataSource;
	_gameBoard = aGameBoard;
	_bossesFactory = new BossesFactory();
	refreshDataSource();
}


CurrentBossDataSource::~CurrentBossDataSource(void)
{
}

vector<AIStrategyInterface*> CurrentBossDataSource::getCurrentBossesAIStrategies()
{
	return _currentBossesAIStrategies;
}

void CurrentBossDataSource::refreshDataSource()
{
	_currentBossesAIStrategies = makeCurrentBossAIStrategies();
}


vector<AIStrategyInterface*> CurrentBossDataSource::makeCurrentBossAIStrategies()
{
	vector<AIStrategyInterface*> aiStrategies = vector<AIStrategyInterface*>();
	GameLevelInformation currentLevelInformation = _currentLevelDataSource->getCurrentLevelData();

	TetraminoBossesInformation bosses = currentLevelInformation.availableBosses;
	for (int bossIndex = 0; bossIndex <= bosses.bossesCount; bossIndex++)
	{
		TetraminoType bossType = bosses.aBossType;
		Tetramino *newBoss = new Tetramino(bossType);
		vector<AIStrategyInterface*> bossAIStrategies = _bossesFactory->getBossAIstrategiesForBossType(newBoss);
		addBossStratagiesToAllStrategies(&bossAIStrategies, &aiStrategies);
	}

	return aiStrategies;

}

void CurrentBossDataSource::addBossStratagiesToAllStrategies(vector<AIStrategyInterface*> *bossStratagies, vector<AIStrategyInterface*> *allStrategies)
{

	vector<AIStrategyInterface*>::iterator bossStratagiesIterator;

	for (bossStratagiesIterator = bossStratagies->begin(); bossStratagiesIterator != bossStratagies->end(); bossStratagiesIterator++)
	{
		allStrategies->push_back(*bossStratagiesIterator);
	}

}