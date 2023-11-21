#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include <map>

class FileManager {
private:
    std::string m_sFileName;

public:
    FileManager(const std::string& sFilename);

    std::vector<std::string> readFileLines();

    std::map<std::string, std::string> getStatsMap(std::vector<std::string> vsFileLines);
    float getStat(std::map<std::string, std::string> mStats, std::string sStat);

    int getInfoPos(std::vector<std::string> vsFileLines);
    std::map<std::string, std::map<std::string, int>> getLevelInfoMap(std::vector<std::string> vsFileLines);
    std::map<int, std::vector<std::string>> getWavesMap(std::vector<std::string> vsFileLines);
    void createLevel(std::map<std::string, std::string> mLevelInfos, std::map<std::string, std::vector<std::string>> mLevelWaves);
};

#endif 
