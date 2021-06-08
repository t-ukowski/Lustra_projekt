#pragma once
#include "Facing.h"
#include "MapObject.h"


class MO1_Emitter : public MapObject {

public:
    MO1_Emitter(int X, int Y, Facing F);

    BeamAction beam(Facing) override;
};


