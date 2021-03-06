#pragma once

#include "cocos2d.h"
#include <vector>
#include <functional>

class SpellsViewDataSource;
class GameTimeStepController;

class PlayerSpellsControllerDesktop : public cocos2d::Node
{
public:
	PlayerSpellsControllerDesktop(void);
	~PlayerSpellsControllerDesktop(void);

	virtual void update(float delta);

	void keyPressed(cocos2d::EventKeyboard::KeyCode aKeyCode, cocos2d::Event *aEvent);

private:

	SpellsViewDataSource *_spellsViewDataSource;
	GameTimeStepController *_gameTimeStepController;
	std::vector<cocos2d::MenuItem*> _spellsIcons;

	std::vector<cocos2d::MenuItem*> makeSpellsIcons();
	void setInSpellViewRechargedIcon(cocos2d::Node* aView);
	std::vector<cocos2d::Node*> makeSpellsViewsWithIcons(std::vector<cocos2d::MenuItem*> aIcons);
	cocos2d::Node* getSpellCostLabelWithIndex(int aSpellIndex);
	cocos2d::Node* getSpellButtonLabelWithIndex(int aSpellIndex);
	void addViewsToController(std::vector<cocos2d::Node*> aViews);
	void setUpKeyboard();
	int getViewIndexForKeyboardKey(int aKeyboardKey);
	void useSpellForIndex(int aIndex);
	std::function<void()> getCallbackWithButtonIndex(int aButtonIndex);
};

