#pragma once
//#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/grid.h>

#include "Map.h"

class Window : public wxFrame {
    Map map;
    

public:

    wxGrid* grid;
    wxButton* HelloWorld;

    Window();
    void OnExit(wxCommandEvent& event);
    

    void setMap(const Map& M) {
        map = M;
    }

    void setup();

    DECLARE_EVENT_TABLE()
};

enum
{
    BUTTON_Hello = wxID_HIGHEST + 1 // declares an id which will be used to call our button
};
