#pragma once
enum class Facing {
    NORTH,
    EAST,
    SOUTH,
    WEST
};
inline const char* toString(Facing f) {
    switch (f)
    {
    case Facing::NORTH: return "N";
    case Facing::EAST:  return "E";
    case Facing::SOUTH: return "S";
    case Facing::WEST:  return "W";
    default:            return "N";
    }
}
inline const Facing nextF(Facing f) {
    switch (f)     {
    case Facing::NORTH: return Facing::EAST;
    case Facing::EAST:  return Facing::SOUTH;
    case Facing::SOUTH: return Facing::WEST;
    case Facing::WEST:  return Facing::NORTH;
    default:            return Facing::NORTH;
    }
}
inline const Facing prevF(Facing f) {
    switch (f) {
    case Facing::NORTH: return Facing::WEST;
    case Facing::EAST:  return Facing::NORTH;
    case Facing::SOUTH: return Facing::EAST;
    case Facing::WEST:  return Facing::SOUTH;
    default:            return Facing::NORTH;
    }
}