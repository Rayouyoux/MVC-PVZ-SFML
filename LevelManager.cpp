#include "LevelManager.h"

LevelManager::LevelManager(int iLevel) {
	string sLevelNumber = to_string(iLevel);
	string sFilePath = "levels/level" + sLevelNumber + ".txt";

	FileManager oLevel(sFilePath);

	vector<string> vsFileLines = oLevel.readFileLines();
	m_mLevelInfo = oLevel.getLevelInfoMap(vsFileLines);
	m_mLevelWaves = oLevel.getLevelWavesMap(vsFileLines);
}

void LevelManager::createLevel(vector<Zombie*> vsZombies) {
	float fSpawnPosX = 1920;
	float fSpawnPosY = 200;
    for (const auto& pair : m_mLevelWaves) {
        const vector<string>& vsWaveInfos = pair.second;
		for (int i = 0; i < vsWaveInfos.size(); i++) {
			for (int j = 0; j < 5; j++) {
				if (vsWaveInfos[j][i] == '-') {
					fSpawnPosX += 60;
				}
				else {
					map<string, int> mZombieInfos;
					for (const auto& innerMap : m_mLevelInfo) {
						if (innerMap.first[0] == vsWaveInfos[j][i]) {
							mZombieInfos.insert(innerMap.second.begin(), innerMap.second.end());
						}
					}
					Zombie oZombie;
					oZombie.setStats(mZombieInfos["SPD"], mZombieInfos["HP"], mZombieInfos["HP"], mZombieInfos["DMG"]);
					vsZombies.push_back(&oZombie);
				}
			}
		}
    }
}