#include "MO6_Tunnel.h"
#include <wx/msgdlg.h>
#include "Audio.h"

MO6_Tunnel::MO6_Tunnel(int X, int Y, Facing F) {
    x = X;
    y = Y;
    facing = F;
    type = 6;
    satisfied = false;
}

void MO6_Tunnel::clicked() {

    Audio::play(Sound::TUNNEL);

    facing = nextF(facing);
}

BeamAction MO6_Tunnel::beam(Facing b) {
    if (facing == Facing::NORTH || facing == Facing::SOUTH) {
        switch (b) {
        case Facing::NORTH: return BeamAction::GO_N;
        case Facing::EAST:  return BeamAction::STOP_NOW;
        case Facing::SOUTH: return BeamAction::GO_S;
        case Facing::WEST:  return BeamAction::STOP_NOW;
        default:            return BeamAction::GO_N;
        }
    }
    switch (b) {
    case Facing::NORTH: return BeamAction::STOP_NOW;
    case Facing::EAST:  return BeamAction::GO_E;
    case Facing::SOUTH: return BeamAction::STOP_NOW;
    case Facing::WEST:  return BeamAction::GO_W;
    default:            return BeamAction::GO_N;
    }
}
