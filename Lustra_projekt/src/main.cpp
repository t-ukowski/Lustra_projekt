#include <iostream>
#include "map_objects/MO1_Emitter.h"
#include "engine/Engine.h"


using namespace std;

int main() {

    Map game_map;
    CSVReader reader;

    Engine game(game_map, reader);

    game.run();
    /** TEMPORARY **/
    game.nextLevel();
    game.nextLevel();

    return 0;
}
