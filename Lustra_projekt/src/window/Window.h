//
// Created by tukow on 04.05.2021.
//

#ifndef LUSTRA_PROJEKT_WINDOW_H
#define LUSTRA_PROJEKT_WINDOW_H

#include <wx/window.h>

#include "../map/Map.h"

class Window {
    Map map;

public:

    void setMap(const Map& M) {
        map = M;
    }

};


#endif //LUSTRA_PROJEKT_WINDOW_H
