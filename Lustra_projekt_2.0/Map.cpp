#include <iostream>
#include "Map.h"
#include "MO1_Emitter.h"
#include "MO2_Collector.h"
#include "MO3_BasicMirror.h"
#include "MO4_Wall.h"
#include "MO5_RetractableMirror.h"
#include "MO6_Tunnel.h"
#include "MO7_SwitchCollectorX.h"
#include "MO8_SwitchCollectorY.h"

Map::Map(int width, int height) {
    levelName = "";
    this->width_ = width;
    this->height_ = height;
    style = 1;
    map = new MapObject * *[height_];
    for (int i = 0; i < height_; ++i) {
        map[i] = new MapObject * [width_];
        for (int j = 0; j < width_; ++j) {
            map[i][j] = nullptr;
        }
    }
}
Map::Map() {
    map = nullptr;
    width_ = 0;
    height_ = 0;
    levelName = "";
}

Map::~Map() {
    deleteOldData();
}

int Map::width() const {
    return width_;
}

int Map::height() const {
    return height_;
}

MapObject*** Map::self() const {
    return map;
}

int Map::getStyle() const {
    return style;
}

string Map::getLevelName() const
{
    return levelName;
}

void Map::loadData(std::vector<std::vector<std::string>> data) {

    if (data.empty()) return;

    deleteOldData();
    levelName = data[0][0];
    style = stoi(data[1][0]);
    height_ = stoi(data[2][0]);
    width_ = stoi(data[2][1]);
    map = new MapObject * *[height_];
    for (int i = 0; i < height_; ++i) {
        map[i] = new MapObject * [width_];
        for (int j = 0; j < width_; ++j) {
            Facing f = Facing::NORTH;
            switch (data[i + 3][j][1]) {
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
            switch (data[i + 3][j][0]) {
            case '1':
                map[i][j] = new MO1_Emitter(i, j, f);
                break;
            case '2':
                map[i][j] = new MO2_Collector(i, j, f);
                break;
            case '3':
                map[i][j] = new MO3_BasicMirror(i, j, f);
                break;
            case '4':
                map[i][j] = new MO4_Wall(i, j, f);
                break;
            case '5':
                map[i][j] = new MO5_RetractableMirror(i, j, f);
                break;
            case '6':
                map[i][j] = new MO6_Tunnel(i, j, f);
                break;
            case '7':
                map[i][j] = new MO7_SwitchCollectorX(i, j, f);
                break;
            case '8':
                map[i][j] = new MO8_SwitchCollectorY(i, j, f);
                break;
            default:
                map[i][j] = nullptr;
                break;
            }
        }
    }
}

string Map::toString() const {
    string s;
    s += levelName + "\n";
    for (int i = 0; i < height_; ++i) {
        for (int j = 0; j < width_; ++j) {
            if (map[i][j] == nullptr) s += "[]";
            else s += map[i][j]->toString();

            if (j < width_ - 1) s += "\'";
            else s += "\n";
        }
    }
    return s;
}

int Map::count(int type) const {
    int c=0;
    for (int i = 0; i < height_; ++i) {
        for (int j = 0; j < width_; ++j) {
            if (map[i][j] != nullptr) {
                if (map[i][j]->getType() == 7 && map[i][j]->getSatisfied() == true) {
                    MapObject* temp = map[i][j];
                    map[i][j] = new MO8_SwitchCollectorY(i, j, temp->getFacing());
                    delete temp;
                }
                if (map[i][j]->getType() == type) {
                    c++;
                }
            }
        }
    }
    return c;
}

string Map::readElem(int i, int j) const
{
    string element;
    if (map[i][j] == nullptr) element = "";
    else element = map[i][j]->toString();
    return element;
}

void Map::deleteOldData() {
    //std::cout << "height: " << height << "width: " << width << std::endl;
    for (int i = 0; i < height_; ++i) {
        for (int j = 0; j < width_; ++j) {
            delete map[i][j];
        }
        delete[] map[i];
    }
    delete[] map;
}
