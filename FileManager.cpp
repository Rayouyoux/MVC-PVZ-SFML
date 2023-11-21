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


float FileManager::getStat(map<string, string> mStats, string sStat) {
    return stof(mStats[sStat]);
}

