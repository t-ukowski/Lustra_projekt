#include "Window.h"
#include <wx/wx.h>
#include <wx/wxprec.h>
#include <iostream>

Window::Window()
    : wxFrame(nullptr, wxID_ANY, wxT("Mirrors"), wxDefaultPosition, wxSize(1000, 1000), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{
    Centre();

}

void Window::OnExit(wxCommandEvent& event) {
    Close(TRUE);
}

void Window::setup() {

    HelloWorld = new wxButton(this, BUTTON_Hello, _T("Hello World"),
        // shows a button on this window
        wxDefaultPosition, wxDefaultSize, 0); // with the text "hello World"

    /*
    grid = new wxGrid(this,
        -1,
        wxPoint(0, 0),
        wxSize(840, 840));

    grid->CreateGrid(21, 21);
    grid->SetRowSize(0, 40);
    grid->SetColSize(0, 40);

    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            grid->SetCellValue(i, j, "kupa");
        }
    }
    grid->SetCellValue(3, 3, "green on grey");
    */

    Show(true);
}

BEGIN_EVENT_TABLE(Window, wxFrame)
EVT_BUTTON(BUTTON_Hello, Window::OnExit) // Tell the OS to run MainFrame::OnExit when
END_EVENT_TABLE() // The button is pressed