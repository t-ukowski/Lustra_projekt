//
// Created by tukow on 27.04.2021.
//

#ifndef LUSTRA_PROJEKT_MAPOBJECT_H
#define LUSTRA_PROJEKT_MAPOBJECT_H

#include <string>

#include "Facing.h"
using std::string;
using std::to_string;

class MapObject {

protected:
    int x;
    int y;
    Facing facing;
    int type;
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
    virtual string toString() const {
        return to_string(type) + ::toString(facing);
    }

    virtual void clicked() {};
};


#endif //LUSTRA_PROJEKT_MAPOBJECT_H
