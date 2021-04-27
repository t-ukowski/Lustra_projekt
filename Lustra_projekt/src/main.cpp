#include <iostream>
#include "map_objects/MO1_Emitter.h"


using namespace std;

int main() {

    MO1_Emitter emitter(0,1,Facing::NORTH);

    cout <<  "Pierwszy obiekt: x=" << emitter.getX() << " y=" << emitter.getY() <<  " facing=" << ToString(emitter.getFacing());

    return 0;
}
