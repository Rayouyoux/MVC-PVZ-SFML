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
    map<string, string> getStatsMap(vector<string> vsFileLines);
    float getStat(map<string, string> mStats, string sStat);

    // Level Methods
    int getInfoPos(vector<string> vsFileLines);
    map<string, map<string, int>> getLevelInfoMap(vector<string> vsFileLines);
    map<int, vector<string>> getLevelWavesMap(vector<string> vsFileLines);

    // Destructor
    ~FileManager();
};

#endif 
