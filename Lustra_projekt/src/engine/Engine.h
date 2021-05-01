//
// Created by tukow on 01.05.2021.
//

#ifndef LUSTRA_PROJEKT_ENGINE_H
#define LUSTRA_PROJEKT_ENGINE_H


#include "../map/Map.h"

class Engine {
    Map map;

public:
    explicit Engine(const Map& M): map(M) {}
    ~Engine();

    void run();
};


#endif //LUSTRA_PROJEKT_ENGINE_H
