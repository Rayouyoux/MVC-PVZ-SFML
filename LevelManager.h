#pragma once

#include <string>
#include <vector>
#include <map>
#include "FileManager.h"

class LevelManager {

public :
	std::map<std::string, std::map<std::string, int>> m_mLevelInfo;
	std::map<int, std::vector<std::string>> m_mLevelWaves;

	LevelManager(int iLevel);

	void createLevel();
};

