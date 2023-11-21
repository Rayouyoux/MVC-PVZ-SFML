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

    std::vector<
};

#endif /* FILEMANAGER_H */
