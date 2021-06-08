#pragma once
#include <vector>
#include <string>
#include "LevelList.h"

using std::string;
using std::vector;

class CSVReader {
    int nextLevel;
public:
    CSVReader() : nextLevel(0) {}
    static vector<string> readLine(string& line);
    vector<vector<string>> readNextLevel();
};
