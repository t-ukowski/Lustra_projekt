//
// Created by tukow on 27.04.2021.
//

#ifndef LUSTRA_PROJEKT_MO1_EMITTER_H
#define LUSTRA_PROJEKT_MO1_EMITTER_H


#include "Facing.h"
#include "MapObject.h"

class MO1_Emitter : public MapObject {

public:
    MO1_Emitter(int X, int Y, Facing F);
};


#endif //LUSTRA_PROJEKT_MO1_EMITTER_H
