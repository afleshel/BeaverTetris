#include "CurrentDetailController.h"
#include "CollisionDelegate.h"
#include "CurrentDetailDataSource.h"
#include "TetraminoDetail.h"
#include "GameBoard.h"
#include <vector>
#include "cocos2d.h"

using namespace std;

CurrentDetailController::CurrentDetailController(GameBoard *aGameBoard, CurrentDetailDataSource *aDetailDataSource)
{
	_gameBoard = aGameBoard;
	_currentDetailDataSource = aDetailDataSource;
	_collisionDelegate = new CollisionDelegate(aGameBoard);
}


CurrentDetailController::~CurrentDetailController(void)
{
}

void CurrentDetailController::moveLeftDetail(void)
{

	GamePositionOnBoard currentDetailPosition = getCurrentDetailPosition();

	if (currentDetailPosition.xPosition > 0)
	{
		GamePositionOnBoard newCurrentDetailPosition = currentDetailPosition;
		newCurrentDetailPosition.xPosition = currentDetailPosition.xPosition - 1;
		setNewPositionIfNoCollision(newCurrentDetailPosition);
	}
	
}

void CurrentDetailController::moveRightDetail(void)
{
	GamePositionOnBoard currentDetailPosition = getCurrentDetailPosition();

	int detailNextPosition = currentDetailPosition.xPosition + 1 + getCurrentDetail()->getDetailWidth();

	if (detailNextPosition > _gameBoard->getGameBoardWidth())
	{
		GamePositionOnBoard newCurrentDetailPosition = currentDetailPosition;
		newCurrentDetailPosition.xPosition = currentDetailPosition.xPosition + 1;
		setNewPositionIfNoCollision(newCurrentDetailPosition);
	}
}

void CurrentDetailController::rotateDetail(void)
{
	TetraminoDetail rotatedTetramino = *getCurrentDetail();
	rotatedTetramino.rotateDetail();

	/*
	bool collide = _collisionDelegate->checkCollisionWithDetail(&rotatedTetramino);

	if (!collide)
	{
		_currentDetail->rotateDetail();
	}
	*/

}

void CurrentDetailController::updateSystem(float deltaTime)
{
	if (_currentDetailDataSource->currentDetailAvailable())
	{
		GamePositionOnBoard newDetailPosition = getCurrentDetail()->getDetailPosition();
		newDetailPosition.yPosition = newDetailPosition.yPosition - 1;

		TetraminoDetail *currentDetail = getCurrentDetail();
		TetraminoDetail *detailWithNewPosition = new TetraminoDetail((*currentDetail));
		detailWithNewPosition->setDetailPosition(newDetailPosition);

		if (_collisionDelegate->checkCollisionDetailWithGameBorders(detailWithNewPosition))
		{
			
		}
		else
		{
			currentDetail->setDetailPosition(newDetailPosition);
		}

	}
}

void CurrentDetailController::setNewPositionIfNoCollision(GamePositionOnBoard aNewDetailPosition)
{
	/*
	TetraminoDetail movedTetramino = *_currentDetail;
	movedTetramino.setDetailPosition(aNewDetailPosition);
	bool collide = _collisionDelegate->checkCollisionWithDetail(&movedTetramino);

	if (!collide)	
	{	
		_currentDetail->setDetailPosition(aNewDetailPosition);	
	}	
	*/

}

TetraminoDetail* CurrentDetailController::getCurrentDetail()
{
	return _currentDetailDataSource->getCurrentDetail();
}

GamePositionOnBoard CurrentDetailController::getCurrentDetailPosition()
{
	TetraminoDetail *currentDetail = getCurrentDetail();
	return currentDetail->getDetailPosition();
}

