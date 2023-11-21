#include "FileManager.h"
#include <iostream>
#include <fstream>

FileManager::FileManager(const std::string& sFilename) : m_sFileName(sFilename) {}

std::vector<std::string> FileManager::readFileLines() {
    std::vector<std::string> lines;
    std::ifstream file(m_sFileName);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << m_sFileName << std::endl;
    }

    return lines;
}

std::map<std::string, std::string> FileManager::getStatsMap(std::vector<std::string> vsFileLines) {
    std::map<std::string, std::string> mStats;

    for (int i = 0; i < vsFileLines.size(); i++) {
        std::size_t pos = vsFileLines[i].find(':');
        mStats[vsFileLines[i].substr(0, pos)] = vsFileLines[i].substr(pos + 1);
    }

    return mStats;
}


float FileManager::getStat(std::map<std::string, std::string> mStats, std::string sStat) {
    return std::stof(mStats[sStat]);
}

