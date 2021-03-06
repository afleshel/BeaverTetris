#pragma once

#include <string>
#include <vector>

class GameFileExtensionMaker
{
public:
	GameFileExtensionMaker(void);
	~GameFileExtensionMaker(void);

	static std::string getGraphicWithExtension(std::string aGraphicKey);
	static std::string getGraphicFramesWithExtension(std::string aGraphicKey);
	static std::string* getGraphicsFilesWithExtension(std::string *aGraphicKey, int arraySize);
	static std::vector<std::string> getGraphicsFilesNamesWithExtension(std::vector<std::string> aSourceKeys);

	static std::string getSoundWithExtension(std::string aSoundKey);
	static std::string* getSoundFilesWithExtension(std::string *aSoundKey, int arraySize);

	static std::string getConfigurationWithExtension(std::string aConfigurationKey);
	static std::string* getConfigurationFilesWithExtension(std::string *aConfigurationKey, int arraySize);

private:
	typedef std::string (* pointerToFunction)(std::string aKey);
	static std::string* getFilesWithExtension(std::string *aGraphicsKeys, int arraySize, pointerToFunction aFunction);

};

