//
// Created by alessandro on 14/09/21.
//

#include "../Stopwatch.h"
#include "gtest/gtest.h"

class SWTest: public ::testing::Test{
protected:
    Stopwatch* s;

    virtual void SetUp(){
        s=new Stopwatch(nullptr,-1);
    };

    virtual void TearDown(){
        delete s;
    };
};

TEST_F(SWTest,SWRunning){
    s->start();
    ASSERT_TRUE(s->isRunning());
    s->stop();
    ASSERT_FALSE(s->isRunning());
}

TEST_F(SWTest,SWOutOfRange){
    s->setSec(60);
    ASSERT_EQ(0,s->getSec());
    ASSERT_EQ(1,s->getMin());
    ASSERT_EQ(0,s->getHour());
    s->setMin(60);
    ASSERT_EQ(0,s->getSec());
    ASSERT_EQ(0,s->getMin());
    ASSERT_EQ(1,s->getHour());
}

TEST_F(SWTest,SWReset){
    s->setSec(40);
    s->start();
    ASSERT_EQ(40,s->getSec());
    ASSERT_TRUE(s->isRunning());
    s->reset();
    ASSERT_EQ(0,s->getSec());
    ASSERT_EQ(0,s->getMin());
    ASSERT_EQ(0,s->getHour());
    ASSERT_FALSE(s->isRunning());
}