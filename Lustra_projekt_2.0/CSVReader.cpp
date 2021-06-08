#include <istream>
#include <fstream>
#include <iostream>
#include "CSVReader.h"

vector<vector<string>> CSVReader::readNextLevel() {
    if (nextLevel < LevelList::listLen) {
        string level = LevelList::getList()[nextLevel];
        nextLevel++;

        std::ifstream inFile;
        inFile.open(level);
        vector<vector<string>> data;
        string line;
        while (!inFile.eof()) {
            std::getline(inFile, line);
            //std::cout << "linia:" << line << std::endl;

            if (inFile.bad() || inFile.fail()) {
                break;
            }
            auto vector_line = readLine(line);
            data.push_back(vector_line);
        }
        inFile.close();
        return data;
    }
    vector<vector<string>> empty;
    return empty;
}

vector<string> CSVReader::readLine(string& line) {
    vector<string> vector_line{ "" };
    size_t i = 0;
    for (char c : line) {
        if (c == ',') {
            vector_line.emplace_back("");
            i++;
        }
        else {
            vector_line[i].push_back(c);
        }
    }
    return vector_line;
}
