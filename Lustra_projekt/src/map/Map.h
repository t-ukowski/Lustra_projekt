//
// Created by tukow on 27.04.2021.
//

#ifndef LUSTRA_PROJEKT_MAP_H
#define LUSTRA_PROJEKT_MAP_H

#include <string>
#include <vector>
#include "../map_objects/MapObject.h"


class Map {
    int width;
    int height;
    MapObject*** map;
    string levelName;

public:

    Map();
    Map(int width, int height);
    ~Map();

    void loadData(std::vector<std::vector<std::string>> data);

    string toString();

    void deleteOldData();
};


#endif //LUSTRA_PROJEKT_MAP_H
