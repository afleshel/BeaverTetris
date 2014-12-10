#pragma once
class SpellInterface
{
public:
	SpellInterface(void);
	~SpellInterface(void);

	virtual bool spellAvailable(void) = 0;
	virtual void castSpell(void) = 0;

};

