//
// Created by tukow on 02.05.2021.
//

#include <string>
#include "LevelList.h"

const int LevelList::listLen = 3;

std::string *LevelList::getList() {
    static std::string list[] = {
            "./src/csv_reader/data/1-10_basic/1.csv",
            "./src/csv_reader/data/1-10_basic/2.csv",
            "./src/csv_reader/data/1-10_basic/3.csv",
    };
    return list;
}

