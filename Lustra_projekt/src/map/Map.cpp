//
// Created by tukow on 27.04.2021.
//

#include <iostream>
#include "Map.h"
#include "./map_objects/MO1_Emitter.h"
#include "./map_objects/MO2_Collector.h"
#include "./map_objects/MO3_BasicMirror.h"
#include "./map_objects/MO4_Wall.h"

Map::Map(int width, int height) {
    levelName = "";
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
Map::Map() {
    map = nullptr;
    width = 0;
    height = 0;
    levelName = "";
}

Map::~Map() {
    deleteOldData();
}

void Map::loadData(std::vector<std::vector<std::string>> data) {
    deleteOldData();
    levelName = data[0][0];
    height = stoi(data[1][0]);
    width = stoi(data[1][1]);
    map = new MapObject**[height];
    for(int i = 0; i < height; ++i) {
        map[i] = new MapObject*[width];
        for(int j = 0; j < width; ++j) {
            Facing f;
            switch(data[i+2][j][1]) {
                case 'N':
                    f = Facing::NORTH;
                    break;
                case 'S':
                    f = Facing::SOUTH;
                    break;
                case 'E':
                    f = Facing::EAST;
                    break;
                case 'W':
                    f = Facing::WEST;
                    break;
                default:
                    break;
            }
            switch(data[i+2][j][0]) {
                case '1':
                    map[i][j] = new MO1_Emitter(i,j,f);
                    break;
                case '2':
                    map[i][j] = new MO2_Collector(i,j,f);
                    break;
                case '3':
                    map[i][j] = new MO3_BasicMirror(i,j,f);
                    break;
                case '4':
                    map[i][j] = new MO4_Wall(i,j,f);
                    break;
                default:
                    map[i][j] = nullptr;
                    break;
            }
        }
    }
}

string Map::toString() {
    string s;
    s += levelName + "\n";
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

void Map::deleteOldData() {
    //std::cout << "height: " << height << "width: " << width << std::endl;
    for(int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            delete map[i][j];
        }
        delete[] map[i];
    }
    delete[] map;
}


