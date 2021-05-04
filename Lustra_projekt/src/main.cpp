#include <iostream>
#include "map/map_objects/MO1_Emitter.h"
#include "engine/Engine.h"


using namespace std;

int main() {

    Map game_map;
    CSVReader reader;
    Window window;

    Engine game(game_map, reader, window);

    game.run();
    /** TEMPORARY **/
    game.nextLevel();
    game.nextLevel();
    game.nextLevel();

    return 0;
}
