//
// Created by tukow on 01.05.2021.
//

#ifndef LUSTRA_PROJEKT_ENGINE_H
#define LUSTRA_PROJEKT_ENGINE_H


#include "../map/Map.h"
#include "../csv_reader/CSVReader.h"

class Engine {
    Map map;
    CSVReader reader;

public:
    Engine(const Map& M, CSVReader R): map(M), reader(R) {}
    ~Engine();

    void run();
    void nextLevel();
};


#endif //LUSTRA_PROJEKT_ENGINE_H
