//
// Created by tukow on 02.05.2021.
//

#ifndef LUSTRA_PROJEKT_CSVREADER_H
#define LUSTRA_PROJEKT_CSVREADER_H


#include <vector>
#include <string>
#include "LevelList.h"

using std::string;
using std::vector;

class CSVReader {
    int nextLevel;
public:
    CSVReader(): nextLevel(0) {}
    static vector<string> readLine(string &line);
    vector<vector<string>> readNextLevel();
};


#endif //LUSTRA_PROJEKT_CSVREADER_H
