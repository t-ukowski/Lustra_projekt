//
// Created by tukow on 01.05.2021.
//

#include "Engine.h"
#include <iostream>
using std::cout;
using std::endl;

void Engine::run() {

    /**TEMPORARY**/
    // remember to add loadEntry()
    map.loadData();
    cout << "nowa mapa:" << endl;
    cout << map.toString() << endl;

}

Engine::~Engine() = default;
