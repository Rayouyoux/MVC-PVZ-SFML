#include "FileManager.h"
#include <iostream>
#include <fstream>

using namespace std;

FileManager::FileManager(const string& sFilename) : m_sFileName(sFilename) {}

vector<string> FileManager::readFileLines() {
    vector<string> lines;
    ifstream file(m_sFileName);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }
    else {
        cerr << "Unable to open file: " << m_sFileName << endl;
    }

    return lines;
}

map<string, string> FileManager::getStatsMap(vector<string> vsFileLines) {
    map<string, string> mStats;

    for (int i = 0; i < vsFileLines.size(); i++) {
        size_t pos = vsFileLines[i].find(':');
        mStats[vsFileLines[i].substr(0, pos)] = vsFileLines[i].substr(pos + 1);
    }

    return mStats;
}

float FileManager::getStat(std::map<std::string, std::string> mStats, std::string sStat) {
    return std::stof(mStats[sStat]);
}

int FileManager::getInfoPos(std::vector<std::string> vsFileLines) {
    int iIndex = 0;
    std::string searchString = "InfosA";

    auto it = std::find(vsFileLines.begin(), vsFileLines.end(), searchString);

    if (it != vsFileLines.end()) {
        iIndex = std::distance(vsFileLines.begin(), it);
    }
    else {
        std::cout << "String not found." << std::endl;
        return -1;
    }

    return iIndex;
}

std::map<std::string, std::map<std::string, int>> FileManager::getLevelInfoMap(std::vector<std::string> vsFileLines) {
    int iIndex = getInfoPos(vsFileLines);
    std::map<std::string, std::map < std::string, int>> mLevelInformations;

    for (int i = iIndex; i < vsFileLines.size(); i = i + 5) {
        std::map<std::string, int> mZombieInfos;

        for (int j = 1; j < 4; j++) {
            std::size_t iColonPos = vsFileLines[i + j].find(':');
            std::string sStatName = vsFileLines[i + j].substr(0, iColonPos);
            std::string sStatValue = vsFileLines[i + j].substr(iColonPos + 1);
            mZombieInfos[sStatName] = std::stoi(sStatValue);
        }

        std::size_t iInfoPos = vsFileLines[i].find("Infos");
        std::string sZombieLetter = vsFileLines[i].substr(iInfoPos + 5);
        mLevelInformations[sZombieLetter] = mZombieInfos;

        mZombieInfos.clear();
    }

    return mLevelInformations;
}

std::map<int, std::vector<std::string>> FileManager::getWavesMap(std::vector<std::string> vsFileLines) {
    int iIndex = getInfoPos(vsFileLines);
    std::map<int, std::vector<std::string>> mLevelWaves;

    for (int i = 0; i < iIndex; i = i + 7) {
        std::vector<std::string> vsWaveInfos;

        for (int j = 1; j < 6; j++) {
            vsWaveInfos.push_back(vsFileLines[i + j]);
        }

        std::size_t iPos = vsFileLines[i].find("Wave");
        int iWaveNumber = std::stoi(vsFileLines[i].substr(iPos + 4));
        mLevelWaves[iWaveNumber] = vsWaveInfos;

        vsWaveInfos.clear();
    }

    return mLevelWaves;
}

void FileManager::createLevel(std::map<std::string, std::string> mLevelInfos, std::map<std::string, std::vector<std::string>> mLevelWaves) {

}