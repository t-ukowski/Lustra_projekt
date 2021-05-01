//
// Created by tukow on 27.04.2021.
//

#include "Map.h"
#include "../map_objects/MO1_Emitter.h"

Map::Map(int width, int height) {
    this->width = width;
    this->height = height;
    map = new MapObject**[height];
    for(int i = 0; i < height; ++i) {
        map[i] = new MapObject*[width];
        for(int j = 0; j < width; ++j) {
            map[i][j] = nullptr;
        }
    }
}

Map::~Map() {
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            delete map[i][j];
        }
        delete[] map[i];
    }


    delete[] map;
}

void Map::loadData() {
    /**TEMPORARY**/
    map[2][3] = new MO1_Emitter(2,3,Facing::WEST);
    map[6][1] = new MO1_Emitter(6,1,Facing::NORTH);
    map[4][7] = new MO1_Emitter(4,7,Facing::SOUTH);
}

string Map::toString() {
    string s;
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            if(map[i][j] == nullptr) s += "[]";
            else s += map[i][j]->toString();

            if(j < width - 1) s += "\'";
            else s += "\n";
        }
    }
    return s;
}
