#include "MO1_Emitter.h"

MO1_Emitter::MO1_Emitter(int X, int Y, Facing F) {
    x = X;
    y = Y;
    facing = F;
    type = 1;
    satisfied = false;
}

BeamAction MO1_Emitter::beam(Facing b) {
    if (facing == b || facing == nextF(nextF(b))) {
        return BeamAction::STOP_NOW;
    }
    switch (b) {
    case Facing::NORTH: return BeamAction::GO_N;
    case Facing::EAST:  return BeamAction::GO_E;
    case Facing::SOUTH: return BeamAction::GO_S;
    case Facing::WEST:  return BeamAction::GO_W;
    default:            return BeamAction::GO_N;
    }
}