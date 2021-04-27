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
inline const char* ToString(Facing f)
{
    switch (f)
    {
        case Facing::NORTH: return "NORTH";
        case Facing::EAST:  return "EAST";
        case Facing::SOUTH: return "SOUTH";
        case Facing::WEST:  return "WEST";
        default:            return "NORTH";
    }
}

#endif //LUSTRA_PROJEKT_FACING_H
