cmake_minimum_required(VERSION 3.17)
project(Lustra_projekt)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
        includes
        D:/STUDIA/SEMESTR_4/C++/wxWidgets-3.1.5
        D:/STUDIA/SEMESTR_4/C++/wxWidgets-3.1.5/include
        D:/STUDIA/SEMESTR_4/C++/wxWidgets-3.1.5/lib/gcc1020_x64_dll/mswud
)

link_directories(
        D:/STUDIA/SEMESTR_4/C++/wxWidgets-3.1.5/lib/gcc1020_x64_dll
        D:/STUDIA/SEMESTR_4/C++/wxWidgets-3.1.5/lib/gcc1020_x64_dll/mswud

)

set(
        WX_LIBS
        libwxmsw31ud_propgrid.a
        libwxmsw31ud_ribbon.a
        libwxmsw31ud_stc.a
        libwxmsw31ud_webview.a
        libwxmsw31ud_gl.a
        libwxmsw31ud_richtext.a
        libwxmsw31ud_xrc.a
        libwxmsw31ud_aui.a
        libwxmsw31ud_html.a
        libwxmsw31ud_adv.a
        libwxmsw31ud_core.a
        libwxbase31ud_xml.a
        libwxbase31ud_net.a
        libwxbase31ud.a
        libwxscintillad.a
        libwxtiffd.a
        libwxjpegd.a
        libwxpngd.a
        libwxzlibd.a
        libwxregexud.a
        libwxexpatd.a
        libwxmsw31ud_media.a
)

add_executable(
        Lustra_projekt src/main.cpp

        src/map/map.cpp src/map/map.h

        src/map/map_objects/Facing.h
        src/map/map_objects/MapObject.cpp src/map/map_objects/MapObject.h
        src/map/map_objects/MO1_Emitter.cpp src/map/map_objects/MO1_Emitter.h
        src/map/map_objects/MO2_Collector.cpp src/map/map_objects/MO2_Collector.h
        src/map/map_objects/MO3_BasicMirror.cpp src/map/map_objects/MO3_BasicMirror.h
        src/map/map_objects/MO4_Wall.cpp src/map/map_objects/MO4_Wall.h

        src/engine/Engine.cpp src/engine/Engine.h

        src/csv_reader/CSVReader.cpp src/csv_reader/CSVReader.h
        src/csv_reader/LevelList.cpp src/csv_reader/LevelList.h

        src/window/Window.cpp src/window/Window.h)

target_link_libraries(
        ${PROJECT_NAME}
        ${WX_LIBS}
)