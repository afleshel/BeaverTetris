#include "FallenDetailAnimationController.h"
#include "AnimationSynchonizer.h"
#include "FallenDetailAnimationFactory.h"
#include "FallenDetailAnimationDelegate.h"
#include "ServiceLocator.h"
#include "GameServicesKeys.h"
#include "TetraminosFallEvent.h"
#include "FillingGapInBoardSystem.h"

using namespace cocos2d;

FallenDetailAnimationController::FallenDetailAnimationController(GameBoardController *aGameBoardController, AnimationSynchonizer *aAnimationSynchonizer)
{
	_animationSynchonizer = aAnimationSynchonizer;
	_gameBoardController = aGameBoardController;
	FallenDetailAnimationDelegate *fallenDetailAnimationDelegate = new FallenDetailAnimationDelegate();
	_fallenDetailAnimationDelegate = fallenDetailAnimationDelegate;
	this->addChild(fallenDetailAnimationDelegate);
	setUpDelegates();
}


FallenDetailAnimationController::~FallenDetailAnimationController(void)
{
}

void FallenDetailAnimationController::setUpDelegates()
{
	FillingGapInBoardSystem *fillingGapInBoardSystem = (FillingGapInBoardSystem*)ServiceLocator::getServiceForKey(fillingGapInBoardSystemKey);
	fillingGapInBoardSystem->setDelegate(this);

	ServiceInterface *service = ServiceLocator::getServiceForKey(tetraminosFallEventModelKey);
	if (service)
	{
		TetraminosFallEvent *tetraminosFallEvent = (TetraminosFallEvent*)service;
		tetraminosFallEvent->setDelegate(this);
	}
}

void FallenDetailAnimationController::placeNewDetailToPosition(TetraminoDetail *aDetail, GamePositionOnBoard aPosition)
{
	DetailViewDataSource *detailViewDataSource = _fallenDetailAnimationDelegate->getDetailViewDataSource(aDetail);
	FallenDetailAnimationFactory *fallenDetailAnimationFactory = new FallenDetailAnimationFactory(detailViewDataSource, _gameBoardController);
	FiniteTimeAction *fallenNewDetailAnimation = _fallenDetailAnimationDelegate->getAnimationWithFactoryAndPosition(fallenDetailAnimationFactory, aPosition);
	delete fallenDetailAnimationFactory;
	_animationSynchonizer->addAnimationToQueue(fallenNewDetailAnimation);
}

void FallenDetailAnimationController::replaceDetailToPosition(TetraminoDetail *aDetail, GamePositionOnBoard aPosition)
{
	DetailViewDataSource *detailViewDataSource = _fallenDetailAnimationDelegate->getDetailViewDataSource(aDetail);
	FallenDetailAnimationFactory *fallenDetailAnimationFactory = new FallenDetailAnimationFactory(detailViewDataSource, _gameBoardController);
	fallenDetailAnimationFactory->cleanDetailViewOnBoard();
	FiniteTimeAction *actionWithDetail = _fallenDetailAnimationDelegate->getReplaceDetailAnimationWithFactoryAndPosition(fallenDetailAnimationFactory, aPosition);
	delete fallenDetailAnimationFactory;
	_animationSynchonizer->addAnimationToQueue(actionWithDetail);
}

