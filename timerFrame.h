//
// Created by alessandro on 02/08/21.
//

#ifndef PROGETTOTIMERLABORATORIO_TIMERFRAME_H
#define PROGETTOTIMERLABORATORIO_TIMERFRAME_H

#include <wx/wx.h>


class timerFrame:public wxFrame {
public:
    timerFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size);

    virtual ~timerFrame();

};


#endif //PROGETTOTIMERLABORATORIO_TIMERFRAME_H
