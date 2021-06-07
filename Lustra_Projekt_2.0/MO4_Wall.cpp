#include "MO4_Wall.h"

MO4_Wall::MO4_Wall(int X, int Y, Facing F) {
    x = X;
    y = Y;
    facing = F;
    type = 4;
    satisfied = false;
}