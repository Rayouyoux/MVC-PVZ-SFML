#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class FileManager {
private:

    string m_sFilePath;

public:

    // Constructor
    FileManager(const string& sFilePath);

    // File Reading
    vector<string> readFileLines();

    // Statistics Methods
    map<string, float> getStatsMap(vector<string> vsFileLines);
    float getStat(map<string, float> mStats, string sStat);

    // Level Methods
    int getInfoPos(vector<string> vsFileLines);
    map<string, map<string, float>> getLevelInfoMap(vector<string> vsFileLines);
    map<int, vector<string>> getLevelWavesMap(vector<string> vsFileLines);

    // Destructor
    ~FileManager();
};

#endif 
