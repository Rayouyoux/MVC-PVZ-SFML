#include "FileManager.h"
#include <iostream>
#include <fstream>

FileManager::FileManager(const string& sFilePath) : m_sFilePath(sFilePath) {}

vector<string> FileManager::readFileLines() {
    vector<string> sLines;
    ifstream fFile(m_sFilePath);

    if (fFile.is_open()) {
        string sLine;
        while (getline(fFile, sLine)) {
            sLines.push_back(sLine);
        }
        fFile.close();
    }
    else {
        cerr << "Unable to open file: " << m_sFilePath << endl;
    }

    return sLines;
}

map<string, string> FileManager::getStatsMap(vector<string> vsFileLines) {
    map<string, string> mStats;

    for (int i = 0; i < vsFileLines.size(); i++) {
        size_t iPos = vsFileLines[i].find(':');
        mStats[vsFileLines[i].substr(0, iPos)] = vsFileLines[i].substr(iPos + 1);
    }

    return mStats;
}

float FileManager::getStat(map<string, string> mStats, string sStat) {
    return stof(mStats[sStat]);
}

int FileManager::getInfoPos(vector<string> vsFileLines) {
    int iIndex = 0;
    string searchString = "InfosA";

    auto it = find(vsFileLines.begin(), vsFileLines.end(), searchString);

    if (it != vsFileLines.end()) {
        iIndex = distance(vsFileLines.begin(), it);
    }
    else {
        cout << "String not found." << endl;
        return -1;
    }

    return iIndex;
}

map<string, map<string, float>> FileManager::getLevelInfoMap(vector<string> vsFileLines) {
    int iIndex = getInfoPos(vsFileLines);
    map<string, map<string, float>> mLevelInformations;

    for (int i = iIndex; i < vsFileLines.size(); i = i + 5) {
        map<string, float> mZombieInfos;

        for (int j = 1; j < 4; j++) {
            size_t iColonPos = vsFileLines[i + j].find(':');
            string sStatName = vsFileLines[i + j].substr(0, iColonPos);
            string sStatValue = vsFileLines[i + j].substr(iColonPos + 1);
            mZombieInfos[sStatName] = stoi(sStatValue);
        }

        size_t iInfoPos = vsFileLines[i].find("Infos");
        string sZombieLetter = vsFileLines[i].substr(iInfoPos + 5);
        mLevelInformations[sZombieLetter] = mZombieInfos;

        mZombieInfos.clear();
    }

    return mLevelInformations;
}

map<int, vector<string>> FileManager::getLevelWavesMap(vector<string> vsFileLines) {
    int iIndex = getInfoPos(vsFileLines);
    map<int, vector<string>> mLevelWaves;

    for (int i = 0; i < iIndex; i = i + 7) {
        vector<string> vsWaveInfos;

        for (int j = 1; j < 6; j++) {
            vsWaveInfos.push_back(vsFileLines[i + j]);
        }

        size_t iPos = vsFileLines[i].find("Wave");
        int iWaveNumber = stoi(vsFileLines[i].substr(iPos + 4));
        mLevelWaves[iWaveNumber] = vsWaveInfos;

        vsWaveInfos.clear();
    }

    return mLevelWaves;
}

FileManager::~FileManager() {}