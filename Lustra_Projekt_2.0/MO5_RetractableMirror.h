#pragma once
#include "Facing.h"
#include "MapObject.h"

class MO5_RetractableMirror : public MapObject {

public:
    MO5_RetractableMirror(int X, int Y, Facing F);

    void clicked() override;

    BeamAction beam(Facing) override;
};
