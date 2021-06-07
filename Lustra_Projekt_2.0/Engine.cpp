#include "Engine.h"
#include <iostream>
using std::cout;
using std::endl;

void Engine::run() {

    window->setMap(map);
    window->setup();
    nextLevel();

}

void Engine::nextLevel() {
    map.loadData(reader.readNextLevel());
    /** TEMPORARY **/
    cout << "Next level:" << endl;
    cout << map.toString() << endl;
}

Engine::~Engine() = default;