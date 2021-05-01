cmake_minimum_required(VERSION 3.17)
project(Lustra_projekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Lustra_projekt src/main.cpp

        src/map/map.cpp src/map/map.h

        src/map_objects/MapObject.cpp src/map_objects/MapObject.h
        src/map_objects/MO1_Emitter.cpp src/map_objects/MO1_Emitter.h

        src/engine/Engine.cpp src/engine/Engine.h
)
