//
// Created by tukow on 27.04.2021.
//

#ifndef LUSTRA_PROJEKT_MAP_H
#define LUSTRA_PROJEKT_MAP_H

#include <string>
#include "../map_objects/MapObject.h"


class Map {
    int width;
    int height;
    MapObject*** map;

public:

    Map(int width, int height);
    ~Map();

    void loadData();

    string toString();
};


#endif //LUSTRA_PROJEKT_MAP_H
