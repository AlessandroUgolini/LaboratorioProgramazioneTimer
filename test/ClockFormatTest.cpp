//
// Created by alessandro on 13/09/21.
//

#include "gtest/gtest.h"
#include "../Clock.h"
#include <cstring>

class ClockTest : public ::testing::Test{
protected:

    Clock* c;
    char timeStr [80];
    std::time_t now;

    virtual void SetUp(){
        c=new Clock(nullptr,-1);
        now=c->getTime();
    };

    virtual void TearDown(){
        delete c;
    };

};

TEST_F(ClockTest, GetTime24){
    std::string myTime=c->getTime24();
    std::strftime(timeStr, 80, "%H:%M:%S", std::localtime(&now));
    std::string timeS(timeStr);
    ASSERT_TRUE(timeS==myTime);
}

TEST_F(ClockTest, GetTime12){
    std::string myTime=c->getTime12();
    std::strftime(timeStr, 80, "%I:%M:%S:%p", std::localtime(&now));
    std::string timeS(timeStr);
    ASSERT_TRUE(timeS==myTime);
}

TEST_F(ClockTest, GetTimeDay) {
    std::string myTime = c->getTimeDay();
    std::strftime(timeStr, 80, "%Y-%m-%d", std::localtime(&now));
    std::string timeS(timeStr);
    ASSERT_TRUE(timeS==myTime);
}

