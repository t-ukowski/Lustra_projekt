//
// Created by tukow on 03.05.2021.
//

#ifndef LUSTRA_PROJEKT_MO4_WALL_H
#define LUSTRA_PROJEKT_MO4_WALL_H

#include "Facing.h"
#include "MapObject.h"

class MO4_Wall : public MapObject {

public:
    MO4_Wall(int X, int Y, Facing F);

};


#endif //LUSTRA_PROJEKT_MO4_WALL_H
