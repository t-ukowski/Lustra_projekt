#include "MO7_SwitchCollectorX.h"
#include <wx/msgdlg.h>
#include "Audio.h"

MO7_SwitchCollectorX::MO7_SwitchCollectorX(int X, int Y, Facing F) {
    x = X;
    y = Y;
    facing = F;
    type = 7;
    satisfied = false;
}

BeamAction MO7_SwitchCollectorX::beam(Facing b) {
    if (b == nextF(nextF(facing))) {
        satisfied = true;
        return BeamAction::SWITCH_COLLECTED;
    }   
    else return BeamAction::STOP_NOW;
}
