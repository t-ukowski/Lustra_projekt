#pragma once
#include "Map.h"
#include "CSVReader.h"
#include "Window.h"

class Engine {
    Map map;
    CSVReader reader;

public:
    Engine(const Map& M, CSVReader R, Window& W) : map(M), reader(R) {}
    ~Engine();

    void run();
    void nextLevel();
};

