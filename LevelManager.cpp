#include "LevelManager.h"
#include "Zombie.h"

/*
---------------------------------------------------------------------------------
|							Here is the constructor								|
---------------------------------------------------------------------------------
*/

LevelManager::LevelManager(int iLevel) {
	string sLevelNumber = to_string(iLevel);
	string sFilePath = "levels/level" + sLevelNumber + ".txt";

	FileManager oLevel(sFilePath);

	vector<string> vsFileLines = oLevel.readFileLines();
	m_mLevelInfo = oLevel.getLevelInfoMap(vsFileLines);
	m_mLevelWaves = oLevel.getLevelWavesMap(vsFileLines);
}

/*
---------------------------------------------------------------------------------
|							Here are the main methods							|
---------------------------------------------------------------------------------
*/

void LevelManager::createLevel(vector<Zombie*> *voZombies) {
	float fSpawnPosX = 1920;
	float fSpawnPosY = 175;
	for (const auto& pair : m_mLevelWaves) {
		const vector<string>& vsWaveInfos = pair.second;
		for (int i = 0; i < vsWaveInfos.size(); i++) {
			for (int j = 0; j < 5; j++) {
				if (vsWaveInfos[j][i] != '-') {
					map<string, float> mZombieInfos;
					for (const auto& innerMap : m_mLevelInfo) {
						if (innerMap.first[0] == vsWaveInfos[j][i]) {
							mZombieInfos.insert(innerMap.second.begin(), innerMap.second.end());
						}
					}
					Zombie* oZombie = new Zombie(mZombieInfos["ID"]);

					oZombie->setStats(mZombieInfos["SPD"], mZombieInfos["HP"], mZombieInfos["HP"], mZombieInfos["DMG"]);
					oZombie->SetPosition(fSpawnPosX, fSpawnPosY + 175 * j);
					voZombies->push_back(oZombie);
				}
			}
			fSpawnPosX += 60;
		}
	}
}
