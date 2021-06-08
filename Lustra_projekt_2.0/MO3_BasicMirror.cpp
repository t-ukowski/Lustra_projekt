#include "MO3_BasicMirror.h"
#include <wx/msgdlg.h>
#include "Audio.h"

MO3_BasicMirror::MO3_BasicMirror(int X, int Y, Facing F) {
    x = X;
    y = Y;
    facing = F;
    type = 3;
    satisfied = false;
}

void MO3_BasicMirror::clicked() {
    
    Audio::play(Sound::BASIC_MIRROR);

    facing = nextF(facing);
}

BeamAction MO3_BasicMirror::beam(Facing b) {
    if (facing == Facing::NORTH || facing == Facing::SOUTH) {
        switch (b) {
        case Facing::NORTH: return BeamAction::GO_E;
        case Facing::EAST:  return BeamAction::GO_N;
        case Facing::SOUTH: return BeamAction::GO_W;
        case Facing::WEST:  return BeamAction::GO_S;
        default:            return BeamAction::GO_N;
        }
    }
    switch (b) {
    case Facing::NORTH: return BeamAction::GO_W;
    case Facing::EAST:  return BeamAction::GO_S;
    case Facing::SOUTH: return BeamAction::GO_E;
    case Facing::WEST:  return BeamAction::GO_N;
    default:            return BeamAction::GO_N;
    }
}
