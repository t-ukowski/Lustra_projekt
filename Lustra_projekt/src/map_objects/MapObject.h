//
// Created by tukow on 27.04.2021.
//

#ifndef LUSTRA_PROJEKT_MAPOBJECT_H
#define LUSTRA_PROJEKT_MAPOBJECT_H


class MapObject {

protected:
    int x;
    int y;
    Facing facing;
public:
    //virtual ~MapObject();
    virtual int getX() const {
        return x;
    }
    virtual int getY() const {
        return y;
    }
    virtual Facing getFacing() const {
        return facing;
    }
};


#endif //LUSTRA_PROJEKT_MAPOBJECT_H
