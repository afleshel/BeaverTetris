#include "GameViewInformationFactory.h"

#include <string>
#include "GameViewElementsKeys.h"
#include "GameFileExtensionMaker.h"

using namespace std;
using namespace cocos2d;

GameViewInformationFactory::GameViewInformationFactory(void)
{
	_elementsInformation =  makeViewData();
}


GameViewInformationFactory::~GameViewInformationFactory(void)
{
	_elementsInformation.clear();
}

void GameViewInformationFactory::setGameElementsInformationInDataSource(GameViewElementsDataSource *aDataSource) 
{
	map <string , ViewElementInformation>::iterator informationIterator ;
	for (informationIterator = _elementsInformation.begin(); informationIterator != _elementsInformation.end(); informationIterator++)
	{
		aDataSource->setViewStructureForKey( (*informationIterator).second , (*informationIterator).first );
	}
}

map <string , ViewElementInformation> GameViewInformationFactory::makeViewData() 
{
	
	ViewElementInformation viewElement1;
	viewElement1.elementImage =  GameFileExtensionMaker::getGraphicWithExtension(gameElement1Key);
	viewElement1.elementPosition = Vec2(10, 10);
	viewElement1.elementZOrder = 3;


	std::map <std::string , ViewElementInformation> viewElementsInformation;
	viewElementsInformation[gameElement1Key] = viewElement1;

	return viewElementsInformation;
}



