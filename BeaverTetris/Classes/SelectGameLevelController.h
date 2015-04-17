#pragma once

#include "PlayerStatusDelegateInterface.h"
#include "cocos2d.h"
#include <vector>

class GameLevelsMenuDataSource;

class SelectGameLevelController : public cocos2d::Node, public PlayerStatusDelegateInterface
{
public:
	SelectGameLevelController(void);
	~SelectGameLevelController(void);

	virtual void showPlayerStatus();

	void setDelegate(PlayerStatusDelegateInterface *aDelegate);

private:

	GameLevelsMenuDataSource *_gameLevelsMenuDataSource;
	cocos2d::Menu* _menuView;
	PlayerStatusDelegateInterface *_delegate;

	void makeScrollableMenuWithBackground(cocos2d::Menu* aMenu);
	std::vector<cocos2d::Node*> getCompletedLevelsSigns();
	void addCompletedLevelSignsToBackground(std::vector<cocos2d::Node*> &aCompletedLevelsSigns, cocos2d::Node *aBackground);
	cocos2d::Node* makeScrollableMenuWithContent(cocos2d::Node* aContentContainer);

	std::vector<cocos2d::MenuItem*> makeLevelsIcons();
	void addLevelIconsToMenu(std::vector<cocos2d::MenuItem*>  aLevelIcons);
	cocos2d::FiniteTimeAction* makeMenuAnimationWithIcons(std::vector<cocos2d::MenuItem*>  aLevelIcons);
	cocos2d::Vector<cocos2d::FiniteTimeAction*> makeActionWithEachIcon(std::vector<cocos2d::MenuItem*>  aLevelIcons);
	cocos2d::FiniteTimeAction* getDelegateAction();
	void buttonWasPressed(cocos2d::Object* pSender);

};

