/*
#include <SFML/Graphics.hpp>

#include "GameManager.h"
#include "GameWindow.h"

using namespace sf;

int main()
{
	GameManager game;
	Event		event;

	// Pour l'instant ici parce que nique et qu'en attendant la version stylée on aura ca

	game.Start();

    return 0;
}
*/

#include "FileManager.h"
#include <iostream>

int main() {
    FileManager level1("levels/level1.txt");

    std::vector<std::string> lines = level1.readFileLines();
    std::map<std::string, std::map < std::string, std::string>> Levelinfoui = level1.getLevelInfoMap(lines);
    std::map<int, std::vector<std::string>> Levelinfnon = level1.getWavesMap(lines);

    std::cout << "Contents of the file:" << std::endl;
    for (const auto& outerPair : Levelinfoui) {
        std::cout << outerPair.first << ":\n";
        for (const auto& innerPair : outerPair.second) {
            std::cout << "  " << innerPair.first << ": " << innerPair.second << "\n";
        }
    }

    for (const auto& pair : Levelinfnon) {
        std::cout << "Key: " << pair.first << ", Values: " << std::endl;

        const auto& vectorOfStrings = pair.second;

        for (const auto& str : vectorOfStrings) {
            std::cout << str << std::endl;
        }

        std::cout << "\n";
    }

    return 0;
}