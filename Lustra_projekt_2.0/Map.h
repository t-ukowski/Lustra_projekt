#pragma once
#include <string>
#include <vector>
#include "MapObject.h"


class Map {
    int width_;
    int height_;
    int style;
    MapObject*** map;
    string levelName;

public:

    Map();
    Map(int width, int height);
    ~Map();

    int width() const;

    int height() const;

    MapObject*** self() const;

    int getStyle() const;

    string getLevelName() const;

    void loadData(std::vector<std::vector<std::string>> data);

    string toString() const;
    
    int count(int) const;

    string readElem(int, int) const;

    void deleteOldData();
};