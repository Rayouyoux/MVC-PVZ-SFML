#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class FileManager {
private:
    string m_sFileName;

public:
    FileManager(const string& sFilename);

    vector<string>              readFileLines();

    map<string, string>         getStatsMap(vector<string> vsFileLines);
    float                       getStat(map<string, string> mStats, string sStat);

    map<string, string>         getLevelInfoMap(vector<string> fileLines);
    map<string, vector<string>> getWavesMap(vector<string> fileLines);

    void                        createLevel(map<string, string> mLevelInfo, map<string, vector<string>> mLevelWaves);
};

#endif 
