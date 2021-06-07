#pragma once
#include "Facing.h"
#include "MapObject.h"

class MO3_BasicMirror : public MapObject {

public:
    MO3_BasicMirror(int X, int Y, Facing F);

    void clicked() override;

    BeamAction beam(Facing) override;
};
