#include "MO2_Collector.h"

MO2_Collector::MO2_Collector(int X, int Y, Facing F) {
    x = X;
    y = Y;
    facing = F;
    type = 2;
    satisfied = false;
}

BeamAction MO2_Collector::beam(Facing b) {
    if (b == nextF(nextF(facing)))
        return BeamAction::COLLECTED;
    else return BeamAction::STOP_NOW;
}
