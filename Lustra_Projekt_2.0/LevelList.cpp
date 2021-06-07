#include <string>
#include "LevelList.h"

const int LevelList::listLen = 17;

std::string* LevelList::getList() {
    static std::string list[] = {
            ".\\data\\maps\\1-10_basic\\1.csv",
            ".\\data\\maps\\1-10_basic\\2.csv",
            ".\\data\\maps\\1-10_basic\\3.csv",
            ".\\data\\maps\\1-10_basic\\4.csv",
            ".\\data\\maps\\1-10_basic\\5.csv",
            ".\\data\\maps\\1-10_basic\\6.csv",
            ".\\data\\maps\\1-10_basic\\7.csv",
            ".\\data\\maps\\1-10_basic\\8.csv",
            ".\\data\\maps\\1-10_basic\\9.csv",
            ".\\data\\maps\\1-10_basic\\10.csv",
            ".\\data\\maps\\11-20_collectors\\1.csv",
            ".\\data\\maps\\11-20_collectors\\2.csv",
            ".\\data\\maps\\11-20_collectors\\3.csv",
            ".\\data\\maps\\11-20_collectors\\4.csv",
            ".\\data\\maps\\11-20_collectors\\5.csv",
            ".\\data\\maps\\11-20_collectors\\6.csv",
            ".\\data\\maps\\11-20_collectors\\7.csv",
    };
    return list;
}