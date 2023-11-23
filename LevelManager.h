#pragma once

#include <string>
#include <vector>
#include <map>

#include "FileManager.h"
#include "GameManager.h"

class Zombie;

using namespace std;

class LevelManager {

public:

	// Main attributes

	map<string, map<string, float>>	m_mLevelInfo;
	map<int, vector<string>>		m_mLevelWaves;

	LevelManager(int iLevel);

	// Main methods

	void createLevel(vector<Zombie*> *voZombies);
};
