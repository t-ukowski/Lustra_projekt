#pragma once
#include "Map.h"
#include "CSVReader.h"
#include "ObjectStrings.h"


class MainApp : public wxApp
{

public:
    virtual bool OnInit();
};

class MainFrame : public wxFrame
{
    Map map;
    CSVReader reader;
    ObjectStrings object_strings;
public:


    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    wxGrid* grid;
    int gridHeight;
    int gridWidth;
    int startingX;
    int startingY;
    int stoppingX;
    int stoppingY;
    int toWin;
    int toPlay;
    //wxButton* nextButton;
    

    void gridClear();
    void mapRefresh();
    void beamRefresh();
    void beamRecursive(int,int,Facing,bool);
    void nextLevel();
    void setCellBackgroundColour_(int i, int j, int type, int style);

    //void nextClicked(wxCommandEvent& event);
    void gridClicked(wxGridEvent& event);
    void gridSelected(wxGridRangeSelectEvent& event);

    //DECLARE_EVENT_TABLE()
};

/*
class MyGridCellRenderer : public wxGridCellStringRenderer {
public:
    virtual void Draw(wxGrid& grid,
        wxGridCellAttr& attr,
        wxDC& dc,
        const wxRect& rect,
        int row, int col,
        bool isSelected);
};
*/

/*
enum
{
    BUTTON_Next = wxID_HIGHEST + 1
};
*/