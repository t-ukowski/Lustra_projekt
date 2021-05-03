//
// Created by tukow on 01.05.2021.
//

#include "Engine.h"
#include <iostream>
using std::cout;
using std::endl;

void Engine::run() {

    nextLevel();

}

void Engine::nextLevel() {
    map.loadData(reader.readNextLevel());
    /** TEMPORARY **/
    cout << "Next level:" << endl;
    cout << map.toString() << endl;
}

Engine::~Engine() = default;
