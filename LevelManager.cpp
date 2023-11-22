#include "LevelManager.h"

LevelManager::LevelManager(int iLevel) {
	std::string sLevelNumber = std::to_string(iLevel);
	std::string sFilePath = "levels/level" + sLevelNumber + ".txt";

	FileManager oLevel(sFilePath);

	std::vector<std::string> vsFileLines = oLevel.readFileLines();
	m_mLevelInfo = oLevel.getLevelInfoMap(vsFileLines);
	m_mLevelWaves = oLevel.getLevelWavesMap(vsFileLines);
}

void LevelManager::createLevel() {

}