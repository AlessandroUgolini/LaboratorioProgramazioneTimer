//
// Created by alessandro on 07/09/21.
//

#include "gtest/gtest.h"
#include "wx/wx.h"

class MyApp: public wxApp {
public:
    virtual bool OnInit();

    virtual int OnRun();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
    return true;
}

int MyApp::OnRun(){
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
}

