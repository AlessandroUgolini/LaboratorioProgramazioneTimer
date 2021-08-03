//
// Created by alessandro on 30/07/21.
//

#ifndef PROGETTOTIMERLABORATORIO_CAPP_H
#define PROGETTOTIMERLABORATORIO_CAPP_H

#include "wx/wx.h"
#include "cMain.h"

class cApp : public wxApp{
public:
    cApp();
    virtual ~cApp();
    bool OnInit();

private:
    cMain* m_frame1=nullptr;
};


#endif //PROGETTOTIMERLABORATORIO_CAPP_H
