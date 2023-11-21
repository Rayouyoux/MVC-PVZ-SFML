#include "FileManager.h"
#include <iostream>
#include <fstream>

FileManager::FileManager(const std::string& filename) : file_name(filename) {}

std::vector<std::string> FileManager::readFileLines() {
    std::vector<std::string> lines;
    std::ifstream file(file_name);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << file_name << std::endl;
    }

    return lines;
}

std::map<std::string, std::string> FileManager::getStatsMap(std::vector<std::string> fileLines) {
    std::map<std::string, std::string> stats;

    for (int i = 0; i < fileLines.size(); i++) {
        std::size_t pos = fileLines[i].find(':');
        stats[fileLines[i].substr(0, pos)] = fileLines[i].substr(pos + 1);
    }

    return stats;
}


float FileManager::getStat(std::map<std::string, std::string> stats, std::string seekedStat) {
    return std::stof(stats[seekedStat]);
}


/*
void FileManager::createLevel(std::vector<std::string> asLevel) {
    std::map<char, std::string> levelInformation;

    for (int i = 3; i < asLevel.size(); i++) {
        levelInformation[asLevel[i][0]] = asLevel[i].substr(1);
    }

    

}
*/