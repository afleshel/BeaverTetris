#include "GameInitiator.h"
#include "ServiceLocator.h"
#include "GameServicesKeys.h"
#include "GameStructures.h"
#include "GameViewElementsDataSource.h"
#include "EventDispatcher.h"
#include "GameTransitionsViewController.h"
#include "PlayerSelectionDataSource.h"
#include "GameTransitionsController.h"
#include "GameGraphicsDataSource.h"
#include "GameViewInformationFactory.h"

GameInitiator::GameInitiator() 
{
	_gameViewElementsDataSource = new GameViewElementsDataSource;
	_eventDispatcher = new EventDispatcher;

}

GameInitiator::~GameInitiator()
{

}

void GameInitiator::setInitialState()
{

	GameViewInformationFactory viewInformationFactory;
	viewInformationFactory.setGameElementsInformationInDataSource(_gameViewElementsDataSource);

	GameTransitionsViewController *gameTransitionsViewController = new GameTransitionsViewController();
	PlayerSelectionDataSource *playerSelectionDataSource = new PlayerSelectionDataSource();
	GameTransitionsController *gameTransitionsController = new GameTransitionsController(gameTransitionsViewController, playerSelectionDataSource);
	_eventDispatcher->setEventHandlerWithEventName(gameTransitionsController, kGoToSceneEvent);
	_eventDispatcher->setEventHandlerWithEventName(gameTransitionsController, kGoToInitualSceneEvent);
	_eventDispatcher->setEventHandlerWithEventName(gameTransitionsController, kGoToPreviousSceneEvent);

	ServiceLocator::setServiceForKey(_gameViewElementsDataSource,gameViewElementsDataSourceKey);
	ServiceLocator::setServiceForKey(_eventDispatcher,eventDispatcherKey);

	GameGraphicsDataSource gameGraphicsDataSource;
	gameGraphicsDataSource.getInitialGraphic();

}