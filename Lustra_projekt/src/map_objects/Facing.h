//
// Created by tukow on 27.04.2021.
//

#ifndef LUSTRA_PROJEKT_FACING_H
#define LUSTRA_PROJEKT_FACING_H


enum class Facing {
    NORTH,
    EAST,
    SOUTH,
    WEST
};
inline const char* toString(Facing f)
{
    switch (f)
    {
        case Facing::NORTH: return "N";
        case Facing::EAST:  return "E";
        case Facing::SOUTH: return "S";
        case Facing::WEST:  return "W";
        default:            return "N";
    }
}

#endif //LUSTRA_PROJEKT_FACING_H
