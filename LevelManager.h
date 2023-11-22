#pragma once

#include <string>
#include <vector>
#include <map>
#include "FileManager.h"
#include "Zombie.h"
#include "GameManager.h"

using namespace std;

class LevelManager {

public :
	map<string, map<string, int>> m_mLevelInfo;
	map<int, vector<string>> m_mLevelWaves;

	LevelManager(int iLevel);

	void createLevel(vector<Zombie*> vsZombies);
};

