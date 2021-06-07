#pragma once
#include "Facing.h"
#include "MapObject.h"

class MO7_SwitchCollectorX : public MapObject {
    
public:

    MO7_SwitchCollectorX(int X, int Y, Facing F);

    BeamAction beam(Facing) override;
};
