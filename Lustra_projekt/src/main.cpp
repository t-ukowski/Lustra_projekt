#include <iostream>
#include "map_objects/MO1_Emitter.h"
#include "engine/Engine.h"
#include "map/Map.h"

#include <string>

using namespace std;

int main() {

    Map game_map(10,10);

    Engine game(game_map);

    game.run();

    return 0;
}
