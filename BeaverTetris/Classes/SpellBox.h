#pragma once

#include "ServiceInterface.h"
#include <string>
#include <map>
#include "GameStructures.h"

class SpellBox : public ServiceInterface
{
public:
	SpellBox();
	~SpellBox(void);

	int getSpellCostForKey(std::string aKey);
	float getSpellRechargePercentForKey(std::string aKey);
	void useSpellForKey(std::string aKey);
	bool spellAvailableForKey(std::string aKey);
	void updateAllSpells();

private:

	std::map<std::string, SpellInformation> _spellsInformations;
	std::map<std::string, int> _spellsCosts;

	void setNewSpellsToPlayer();
	std::map<std::string, LevelSpellInformation> getSpellsData();
	std::map<std::string, int> getSpellsCosts();
	std::map<std::string, SpellInformation> getSpellsInformation();

};

