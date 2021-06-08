#include "MO5_RetractableMirror.h"
#include "Audio.h"

MO5_RetractableMirror::MO5_RetractableMirror(int X, int Y, Facing F) {
    x = X;
    y = Y;
    facing = F;
    type = 5;
    satisfied = false;
}

void MO5_RetractableMirror::clicked() {
    if(facing == Facing::NORTH || facing == Facing::EAST)
        Audio::play(Sound::RETRACTABLE_MIRROR_DOWN);
    else
        Audio::play(Sound::RETRACTABLE_MIRROR_UP);

    facing = nextF(nextF(facing));
}

BeamAction MO5_RetractableMirror::beam(Facing b) {
    if (facing == Facing::NORTH) {
        switch (b) {
        case Facing::NORTH: return BeamAction::GO_E;
        case Facing::EAST:  return BeamAction::GO_N;
        case Facing::SOUTH: return BeamAction::GO_W;
        case Facing::WEST:  return BeamAction::GO_S;
        default:            return BeamAction::GO_N;
        }
    }
    if (facing == Facing::EAST) {
        switch (b) {
        case Facing::NORTH: return BeamAction::GO_W;
        case Facing::EAST:  return BeamAction::GO_S;
        case Facing::SOUTH: return BeamAction::GO_E;
        case Facing::WEST:  return BeamAction::GO_N;
        default:            return BeamAction::GO_N;
        }
    }
    switch (b) {
    case Facing::NORTH: return BeamAction::GO_N;
    case Facing::EAST:  return BeamAction::GO_E;
    case Facing::SOUTH: return BeamAction::GO_S;
    case Facing::WEST:  return BeamAction::GO_W;
    default:            return BeamAction::GO_N;
    }
}