#pragma once
#include "Facing.h"
#include "MapObject.h"

class MO6_Tunnel : public MapObject {

public:
    MO6_Tunnel(int X, int Y, Facing F);

    void clicked() override;

    BeamAction beam(Facing) override;
};

