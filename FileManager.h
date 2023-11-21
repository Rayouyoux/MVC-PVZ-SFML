#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include <map>

class FileManager {
private:
    std::string file_name;

public:
    FileManager(const std::string& filename);

    std::vector<std::string> readFileLines();

    std::map<std::string, std::string> getStatsMap(std::vector<std::string> fileLines);
    float getStat(std::map<std::string, std::string> stats, std::string seekedStat);


};

#endif /* FILEMANAGER_H */
