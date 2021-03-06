#pragma once

#include "SpellInterface.h"
#include "ServiceInterface.h"
#include "FuctionsTypedefs.h"
#include "GameStructures.h"

class GameBoard;
class FirestormSpellDelegate;
class CurrentDetailDataSource;
class FirestromSpellExplosionPositionDelegate;
class SpellRechargeDelegate;

class FirestromSpell :public SpellInterface, public ServiceInterface
{
public:
	FirestromSpell(void);
	~FirestromSpell(void);

	virtual bool spellAvailable();
	virtual void castSpell();
	virtual void updateSpell();
	virtual float getSpellRechargePercent();

	void setDelegate(FirestormSpellDelegate *aDelegate);

private:

	GameBoard *_gameBoard;
	FirestormSpellDelegate *_delegate;
	int _meteorsCount;
	SpellRechargeDelegate *_spellRechargeDelegate;
	CurrentDetailDataSource *_currentDetailDataSource;
	FirestromSpellExplosionPositionDelegate *_explosionPositionDelegate;
	bool _removeCurrentDetail;
	GamePositionOnBoard _explosionPositionInCurrentDetail;

	std::vector<FireballInformation> getFireballs();
	GamePositionOnBoard getExplosionPosition();
	FireballInformation  getFireballFromPosition(GamePositionOnBoard aExplosionPosition);
	void removeCurrentDetail();
	void throwFireballs(std::vector<FireballInformation> aFireballs);
	void sendMassegeToDelegateWithFireballs(std::vector<FireballInformation> aFireballs);
	void removeKilledTetraminosFromFireballs(std::vector<FireballInformation> aFireballs);
	void removeKilledTetraminosFromExplosionZone(std::vector<GamePositionOnBoard> aExplosionsZone);
	void reduceLiveOnPosition(GamePositionOnBoard aPosition);
	void sendDelegateKilledTetraminoOnPosition(GamePositionOnBoard aPosition);
	void sendMassegeToDelegateToDeleteCurrentDetailWithPosition(GamePositionOnBoard aExplosionPosition);

};

