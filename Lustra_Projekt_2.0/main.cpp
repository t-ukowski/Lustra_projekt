#include <wx/wxprec.h>
#include <wx/grid.h>
#include <wx/colour.h>
#include <wx/msgdlg.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>

#endif
#include "main.h"
#include "Audio.h"


IMPLEMENT_APP(MainApp) // Initializes the MainApp class and tells our program
// to run it
bool MainApp::OnInit()
{
    // Create an instance of our frame, or window
    MainFrame* MainWin = new MainFrame(_T("Hello World!"), wxDefaultPosition, wxSize(1067, 1092));
    MainWin->Show(TRUE); // show the window
    SetTopWindow(MainWin); // and finally, set it as the main window

    return TRUE;
}

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize
    & size) : wxFrame((wxFrame*)NULL, -1, title, pos, size)
{
    map = Map();
    reader = CSVReader();
    
    //nextButton = new wxButton(this, BUTTON_Next, _T("Next\nLevel"),
       // wxDefaultPosition, wxSize(50, 50), 0);

    gridHeight = 21;
    gridWidth = 21;
    object_strings = ObjectStrings(gridHeight, gridWidth);

    startingX = 0;
    startingY = 0;
    stoppingX = 0;
    stoppingY = 0;
    toWin = 100;
    grid = new wxGrid(this,
        -1,
        wxPoint(0, 0),
        wxSize(1050, 1050));

    grid->CreateGrid(gridHeight, gridWidth);
    grid->SetRowLabelSize(0);
    grid->SetColLabelSize(0);
    grid->EnableEditing(false);
    grid->DisableDragColSize();
    grid->DisableDragRowSize();

    for (int i = 0; i < gridHeight; i++) {
        grid->SetColSize(i, 50);
        grid->SetRowSize(i, 50);
        for (int j = 0; j < gridWidth; j++) {
            grid->SetCellOverflow(i, j, true);
            grid->SetCellAlignment(i, j, wxALIGN_CENTRE, wxALIGN_CENTRE);
        }
    }
    //MIRRORS
    for (int j = 0; j < gridWidth; j++) {
        grid->SetCellTextColour(0, j, *wxWHITE);
        grid->SetCellBackgroundColour(0, j, *wxBLACK);
    }
    for (int j = 7; j < 14; j++) {
        grid->SetCellFont(0, j, wxFont(25, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    }
    grid->SetCellValue(0, 7, "M");
    grid->SetCellValue(0, 8, "I");
    grid->SetCellValue(0, 9, "R");
    grid->SetCellValue(0, 10, "R");
    grid->SetCellValue(0, 11, "O");
    grid->SetCellValue(0, 12, "R");
    grid->SetCellValue(0, 13, "S");

    grid->SetCellFont(0, 0, wxFont(11, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    grid->SetCellFont(0, 14, wxFont(18, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    grid->SetCellSize(0, 14, 1, 7);
    
    wxMemoryDC dc;
    //grid->SetCellRenderer(4, 4, new MyGridCellRenderer);
    //grid->Render(dc, );

    grid->Bind(wxEVT_GRID_CELL_LEFT_DCLICK, &MainFrame::gridClicked, this);
    grid->Bind(wxEVT_GRID_RANGE_SELECT, &MainFrame::gridSelected, this);

    nextLevel();
}
/*
void MyGridCellRenderer::Draw(wxGrid& grid,
    wxGridCellAttr& attr,
    wxDC& dc,
    const wxRect& rect,
    int row, int col,
    bool isSelected) {
    wxGridCellStringRenderer::Draw(grid, attr, dc, rect, row, col, isSelected);

    dc.SetPen(*wxGREEN_PEN);
    dc.SetBrush(*wxTRANSPARENT_BRUSH);
    dc.DrawEllipse(rect);
}
*/
void MainFrame::gridClear()
{
    for (int i = 1; i < gridHeight; i++) {
        for (int j = 0; j < gridWidth; j++) {
            grid->SetCellValue(i, j, "");
            setCellBackgroundColour_(i, j, 0, map.getStyle());
        }
    }
    grid->SetCellValue(0, 0, "");
}

void MainFrame::mapRefresh() {
    toWin = map.count(2);
    //toWin = 0;

    beamRefresh();

    for (int i = startingY; i < stoppingY; i++) {
        for (int j = startingX; j < stoppingX; j++) {
            setCellBackgroundColour_(i, j, 1, map.getStyle());
            grid->SetCellFont(i, j, wxFont(1, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
            grid->SetCellValue(i, j, object_strings.stringify(map.readElem(i - startingY, j - startingX), i, j));
        }
    }

    this->Refresh();
    if (toWin <= 0 && map.count(7) == 0) {
        grid->SetCellValue(0, 0, "Next\nLevel");
    } else {
        grid->SetCellValue(0, 0, "");
    }
    
}

void MainFrame::beamRefresh() {
    object_strings.clear();
    for (int i = startingY; i < stoppingY; i++) {
        for (int j = startingX; j < stoppingX; j++) {
            if (map.readElem(i - startingY, j - startingX) != "") {
                if (map.readElem(i - startingY, j - startingX).front() == '1') {
                    //wxMessageBox(wxT("dziala!"));
                    beamRecursive(i, j, map.self()[i - startingY][j - startingX]->getFacing(), true);
                }
            }
        }
    }
}

void MainFrame::beamRecursive(int i, int j, Facing f, bool beginning) {
    BeamAction what_next = BeamAction::STOP_NOW;
    //wxMessageBox(wxT("1"));
    if (i >= startingY && i < stoppingY && j >= startingX && j < stoppingX) {
        //wxMessageBox(wxT("2"));
        if (!beginning && map.readElem(i - startingY, j - startingX) != "") {
            what_next = map.self()[i - startingY][j - startingX]->beam(f);
        } else {
            switch (f) {
            case Facing::NORTH:
                what_next = BeamAction::GO_N;
                break;
            case Facing::EAST:
                what_next = BeamAction::GO_E;
                break;
            case Facing::SOUTH:
                what_next = BeamAction::GO_S;
                break;
            case Facing::WEST:
                what_next = BeamAction::GO_W;
                break;
            default:
                break;
            }
        }
    }
    if (!beginning && what_next != BeamAction::STOP_NOW)
        switch (f) {
        case Facing::NORTH:
            object_strings.add(1, i, j);
            //wxMessageBox(wxT("1"));
            break;
        case Facing::EAST:
            object_strings.add(10, i, j);
            //wxMessageBox(wxT("10"));
            break;
        case Facing::SOUTH:
            object_strings.add(100, i, j);
            //wxMessageBox(wxT("100"));
            break;
        case Facing::WEST:
            object_strings.add(1000, i, j);
            //wxMessageBox(wxT("1000"));
            break;
        default:
            break;
        }
        //grid->SetCellBackgroundColour(i, j, wxColor(255, 255, 200, wxALPHA_OPAQUE));
    switch (what_next)     {
    case BeamAction::STOP_NOW:
        break;
    case BeamAction::GO_N:
        beamRecursive(i-1, j, Facing::NORTH, false);
        object_strings.add(100, i, j);
        break;
    case BeamAction::GO_E:
        beamRecursive(i, j+1, Facing::EAST, false);
        object_strings.add(1000, i, j);
        break;
    case BeamAction::GO_S:
        beamRecursive(i+1, j, Facing::SOUTH, false);
        object_strings.add(1, i, j);
        break;
    case BeamAction::GO_W:
        beamRecursive(i, j-1, Facing::WEST, false);
        object_strings.add(10, i, j);
        break;
    case BeamAction::COLLECTED:
        toWin--;
        if (toPlay > 0 && toWin <= 0 && map.count(7) == 0) {
            Audio::play(Sound::COLLECTED);
            toPlay = 0;
        }
        break;
    default:
        break;
    }
}

void MainFrame::nextLevel()
{
    map.loadData(reader.readNextLevel());
    
    gridClear();
    string name = map.getLevelName();
    if(name.length()>=25) grid->SetCellFont(0, 14, wxFont(13, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    else grid->SetCellFont(0, 14, wxFont(18, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->SetLabel(name);
    
    grid->SetCellValue(0, 14, name);

    startingY = (gridHeight - map.height()) / 2;
    startingX = (gridWidth - map.width()) / 2;
    stoppingY = map.height() + startingY;
    stoppingX = map.width() + startingX;
    toWin = map.count(2);
    toPlay = 1;

    mapRefresh();
}
void MainFrame::setCellBackgroundColour_(int i, int j, int type, int style) {
    switch (style) {
    case(1):
        switch (type) {
        case(0):
            grid->SetCellBackgroundColour(i, j, *wxLIGHT_GREY);
            break;
        case(1):
            grid->SetCellBackgroundColour(i, j, *wxWHITE);
            break;
        default:
            break;
        }
        break;
    case(2):
        switch (type) {
        case(0):
            if (j % 2 == 0) {
                grid->SetCellBackgroundColour(i, j, wxColor(98, 209, 107, 255));
            } else {
                grid->SetCellBackgroundColour(i, j, wxColor(90, 201, 99, 255));
            }
            break;
        case(1):
            grid->SetCellBackgroundColour(i, j, wxColor(227, 255, 227, 255));
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    
}
/*
void MainFrame::nextClicked(wxCommandEvent& event)
{
    nextLevel();
}
*/

void MainFrame::gridClicked(wxGridEvent& event)
{
    long loc_ul_column = event.GetCol();
    long loc_ul_row = event.GetRow();

    if(loc_ul_column == 0 && loc_ul_row == 0 && toWin <= 0) {
        nextLevel();
    }
    else if(
        loc_ul_column >= startingX &&
        loc_ul_column < stoppingX &&
        loc_ul_row >= startingY &&
        loc_ul_row < stoppingY &&
        map.self()[loc_ul_row - startingY][loc_ul_column-startingX] != nullptr
    ) {
         map.self()[loc_ul_row - startingY][loc_ul_column-startingX]->clicked();
    }
    mapRefresh();
}

void MainFrame::gridSelected(wxGridRangeSelectEvent& event)
{
    wxGridCellCoordsArray selTop = this->grid->GetSelectionBlockTopLeft();
    wxGridCellCoordsArray selBottom = this->grid->GetSelectionBlockBottomRight();
    for (size_t i = 0; i < selTop.Count(); i++)
    {
        this->grid->ClearSelection();
    }
}

//BEGIN_EVENT_TABLE(MainFrame, wxFrame)
//EVT_BUTTON(BUTTON_Next, MainFrame::nextClicked)
//END_EVENT_TABLE()