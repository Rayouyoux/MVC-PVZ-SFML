#include "LevelManager.h"

LevelManager::LevelManager(int iLevel) {
	string sLevelNumber = to_string(iLevel);
	string sFilePath = "levels/level" + sLevelNumber + ".txt";

	FileManager oLevel(sFilePath);

	vector<string> vsFileLines = oLevel.readFileLines();
	m_mLevelInfo = oLevel.getLevelInfoMap(vsFileLines);
	m_mLevelWaves = oLevel.getLevelWavesMap(vsFileLines);
}

void LevelManager::createLevel() {
	float fSpawnPosX = 1920;
	float fSpawnPosY = 100;
    for (const auto& pair : m_mLevelWaves) {
        const vector<string>& vsWaveInfos = pair.second;
		for (int i = 0; i < vsWaveInfos.size(); i++) {
			for (int j = 0; j < 5; j++) {
				if (vsWaveInfos[j][i] == '-') {
					/*rien*/
				}
				else {
					/*check letter*/
					/*Spawn zombie with level info*/
				}
			}
		}
    }
}