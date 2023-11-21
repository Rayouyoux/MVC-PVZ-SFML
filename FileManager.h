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

    std::map<std::string, std::string> getLevelInfoMap(std::vector<std::string> fileLines);
    std::map<std::string, std::vector<std::string>> getWavesMap(std::vector<std::string> fileLines);
    void createLevel(std::map<std::string, std::string> mLevelInfo, std::map<std::string, std::vector<std::string>> mLevelWaves);
};

#endif 
