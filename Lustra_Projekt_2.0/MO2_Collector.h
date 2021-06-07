#pragma once
#include "Facing.h"
#include "MapObject.h"

class MO2_Collector : public MapObject {

public:
    MO2_Collector(int X, int Y, Facing F);

    BeamAction beam(Facing) override;
};



