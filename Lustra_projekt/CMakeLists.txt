cmake_minimum_required(VERSION 3.17)
project(Lustra_projekt)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(
        Lustra_projekt src/main.cpp

        src/map/map.cpp src/map/map.h

        src/map_objects/Facing.h
        src/map_objects/MapObject.cpp src/map_objects/MapObject.h
        src/map_objects/MO1_Emitter.cpp src/map_objects/MO1_Emitter.h
        src/map_objects/MO2_Collector.cpp src/map_objects/MO2_Collector.h
        src/map_objects/MO3_BasicMirror.cpp src/map_objects/MO3_BasicMirror.h
        src/map_objects/MO4_Wall.cpp src/map_objects/MO4_Wall.h

        src/engine/Engine.cpp src/engine/Engine.h

        src/csv_reader/CSVReader.cpp src/csv_reader/CSVReader.h
        src/csv_reader/LevelList.cpp src/csv_reader/LevelList.h
        
)
