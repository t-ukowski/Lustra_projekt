#pragma once
#include <string>

#include "Facing.h"
#include "BeamAction.h"

using std::string;
using std::to_string;

class MapObject {

protected:
    int x;
    int y;
    Facing facing;
    int type;
    bool satisfied;
public:
    virtual ~MapObject();
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
    Facing getFacing() const {
        return facing;
    }
    int getType() const {
        return type;
    }
    bool getSatisfied() const {
        return satisfied;
    }
    virtual string toString() const {
        return to_string(type) + ::toString(facing);
    }

    virtual void clicked() {};

    virtual BeamAction beam(Facing) { return BeamAction::STOP_NOW; }
};

