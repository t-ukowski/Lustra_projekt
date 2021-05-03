//
// Created by tukow on 03.05.2021.
//

#ifndef LUSTRA_PROJEKT_MO3_BASICMIRROR_H
#define LUSTRA_PROJEKT_MO3_BASICMIRROR_H

#include "Facing.h"
#include "MapObject.h"

class MO3_BasicMirror : public MapObject {

public:
    MO3_BasicMirror(int X, int Y, Facing F);
};


#endif //LUSTRA_PROJEKT_MO3_BASICMIRROR_H
