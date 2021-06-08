#include "MO8_SwitchCollectorY.h"
#include <wx/msgdlg.h>
#include "Audio.h"

MO8_SwitchCollectorY::MO8_SwitchCollectorY(int X, int Y, Facing F) {
    x = X;
    y = Y;
    facing = F;
    type = 8;
    satisfied = false;
}