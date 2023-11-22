#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include <map>

class FileManager {
private:
    std::string m_sFilePath;

public:
    FileManager(const std::string& sFilePath);

    std::vector<std::string> readFileLines();

    std::map<std::string, std::string> getStatsMap(std::vector<std::string> vsFileLines);
    float getStat(std::map<std::string, std::string> mStats, std::string sStat);

    int getInfoPos(std::vector<std::string> vsFileLines);
    std::map<std::string, std::map<std::string, int>> getLevelInfoMap(std::vector<std::string> vsFileLines);
    std::map<int, std::vector<std::string>> getLevelWavesMap(std::vector<std::string> vsFileLines);
};

#endif 
