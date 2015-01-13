#include "GameSoundDataSource.h"
#include "GameFileExtensionMaker.h"

using namespace std;

const string sound1Name = string("StartGraphics");
const string sound2Name = string("StartGraphics");

GameSoundDataSource::GameSoundDataSource(void)
{
	
}


GameSoundDataSource::~GameSoundDataSource(void)
{
}


int GameSoundDataSource::getSoundsCount(void)
{
	return _soundsElementsCount;
}

string GameSoundDataSource::getSoundForIndex(int aIndex)
{
	return _sounds[aIndex];
}