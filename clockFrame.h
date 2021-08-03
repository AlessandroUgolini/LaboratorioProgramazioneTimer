//
// Created by alessandro on 02/08/21.
//

#ifndef PROGETTOTIMERLABORATORIO_CLOCKFRAME_H
#define PROGETTOTIMERLABORATORIO_CLOCKFRAME_H

#include <wx/wx.h>

class clockFrame :public wxFrame {
public:
    clockFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size);

    virtual ~clockFrame();
};


#endif //PROGETTOTIMERLABORATORIO_CLOCKFRAME_H
