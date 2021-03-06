#include "LoadGameController.h"
#include "LoadingGameDataSource.h"
#include "GameAnimationActionsConstants.h"
#include "GameStatesHelper.h"
#include "CocosNodesHelper.h"
#include "GameViewElementsKeys.h"

using namespace std;
using namespace cocos2d;

LoadGameController::LoadGameController(void)
{
	Sprite *sourceView = CocosNodesHelper::getSpriteWithKey(loadingGameClockKey);
	_loadGameControllerView =  ProgressTimer::create(sourceView);
	_loadGameControllerView->setPercentage(100);
	_loadGameControllerView->setReverseDirection(true);
	this->addChild(_loadGameControllerView);

	_loadingGameDataSource = new LoadingGameDataSource();
	_loadedResourcesCount = 0;

}

LoadGameController::~LoadGameController(void)
{
}

void LoadGameController::onEnterTransitionDidFinish()
{
	loadGameResource();
}

void LoadGameController::loadGameResource()
{
	int resourcesCount = _loadingGameDataSource->getResourcesCount();

	if (_loadedResourcesCount < resourcesCount)
	{
		loadOneResource();
	}
	else
	{
		GameStatesHelper::goToScene(kStartGame);
	}

}

void LoadGameController::loadOneResource()
{
	int loadingPercent = _loadingGameDataSource->getResourceLoadingPercentForIndex(_loadedResourcesCount);
	_loadingGameDataSource->loadResouceForIndex(_loadedResourcesCount);
	_loadedResourcesCount++;
	runLoadingActionWithLoadingPercent(loadingPercent);
}

void LoadGameController::runLoadingActionWithLoadingPercent(int aLoadingPercent)
{
	int currentPercent = _loadGameControllerView->getPercentage();
	float actionDuration = 0.06 * aLoadingPercent;
	
	FiniteTimeAction *progressAction = ProgressFromTo::create(actionDuration, currentPercent, currentPercent - aLoadingPercent);
	FiniteTimeAction *callback = CallFunc::create(this, CC_CALLFUNC_SELECTOR(LoadGameController::loadGameResource));
	Action *sequence = Sequence::create(progressAction, callback, NULL);
	_loadGameControllerView->runAction(sequence);
}