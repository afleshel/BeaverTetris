#pragma once

#include <string>
#include "cocos2d.h"
#include "GameStructures.h"

class GameViewInformationFactory
{
public:
	GameViewInformationFactory(void);
	~GameViewInformationFactory(void);

	ViewElementInformation getViewInformationForKey(std::string aKey);

private:

	std::map <std::string , ViewElementInformation> _elementsInformation;

	void makeViewData();

	void makeLoadingScreenData();
	void makeStartGameSreenData();
	void makeStartGameRegulateSoundPopUpData();
	void makeSelectGameLevelScreenData();
	void makeSelectGameLevelMenuData();
	void makeSelectGameLevelPlayerStatusData();
	void makeSelectGameLevelPlayerCreatorControllerData();
	void makeMainGameScreenData();
	void makeMainGameWorldData();
	void makeMainGameHudsData();
	void makeMainGamePlayerControllersData();
	void makeMainGamePlayerScoreControllersData();
	void makeRecordsScreenData();
	void makeDevelopersScreenData();

	cocos2d::Vec2 getScreenCenter();
	float getScreenCenterX();
	float getScreenCenterY();
	std::string getImageNameForKey(std::string aKey);

};

