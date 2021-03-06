#include "CurrentVictoryConditionDataSource.h"
#include "VictoryConditionInterface.h"
#include "StringsSupporter.h"
#include "VictoryConditionInterface.h"
#include "CurrentLevelDataSource.h"

#include "WinBossCondition.h"
#include "PlaceSomeDetailsCondition.h"
#include "RemainSomeTimeCondition.h"
#include "RemoveSomeTetraminosCondition.h"

using namespace std;

CurrentVictoryConditionDataSource::CurrentVictoryConditionDataSource(CurrentLevelDataSource *aCurrentLevelDataSource)
{
	CurrentLevelDataSource *currentLevelDataSource = aCurrentLevelDataSource;
	GameLevelInformation levelData = currentLevelDataSource->getCurrentLevelData();
	_currentVictoryCondition = getVictoryConditionWithLevelData(levelData);
}


CurrentVictoryConditionDataSource::~CurrentVictoryConditionDataSource(void)
{
}

VictoryConditionInterface* CurrentVictoryConditionDataSource::getVictoryConditionWithLevelData(GameLevelInformation data)
{
	map< VictoryConditionType, function<VictoryConditionInterface*(GameLevelInformation)> > victoryConditions = getVictoryConditions();
	function<VictoryConditionInterface*(GameLevelInformation)> conditionFactory = victoryConditions[data.victoryConditionType];
	VictoryConditionInterface *currentVictoryCondition = conditionFactory(data);
	return currentVictoryCondition;
}

map< VictoryConditionType, function<VictoryConditionInterface*(GameLevelInformation)> > CurrentVictoryConditionDataSource::getVictoryConditions()
{
	map< VictoryConditionType, function<VictoryConditionInterface*(GameLevelInformation)> > victoryConditions;

	victoryConditions[kWinBossCondition] = [](GameLevelInformation data){
		VictoryConditionInterface *victoryCondition = new WinBossCondition(data);
		return victoryCondition;
	};

	victoryConditions[kPlaceSomeDetailsCondition] = [](GameLevelInformation data){
		VictoryConditionInterface *victoryCondition = new PlaceSomeDetailsCondition(data);
		return victoryCondition;
	};

	victoryConditions[kRemainSomeTimeCondition] = [](GameLevelInformation data){
		VictoryConditionInterface *victoryCondition = new RemainSomeTimeCondition(data);
		return victoryCondition;
	};

	victoryConditions[kRemoveSomeTetraminosCondition] = [](GameLevelInformation data){
		VictoryConditionInterface *victoryCondition = new RemoveSomeTetraminosCondition(data);
		return victoryCondition;
	};

	return victoryConditions;
}

VictoryConditionInterface* CurrentVictoryConditionDataSource::getCurrentVictoryCondition()
{
	return _currentVictoryCondition;
}
