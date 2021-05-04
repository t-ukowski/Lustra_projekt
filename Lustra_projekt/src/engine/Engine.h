//
// Created by tukow on 01.05.2021.
//

#ifndef LUSTRA_PROJEKT_ENGINE_H
#define LUSTRA_PROJEKT_ENGINE_H


#include "../map/Map.h"
#include "../csv_reader/CSVReader.h"
#include "../window/Window.h"

class Engine {
    Map map;
    CSVReader reader;
    Window window;

public:
    Engine(const Map& M, CSVReader R, Window W): map(M), reader(R), window(W) {}
    ~Engine();

    void run();
    void nextLevel();
};


#endif //LUSTRA_PROJEKT_ENGINE_H
