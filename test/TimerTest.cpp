//
// Created by alessandro on 14/09/21.
//
#include "gtest/gtest.h"
#include "../Timer.h"

class TimerTest: public ::testing::Test{
protected:
    Timer* t;

    virtual void SetUp(){
        t=new Timer(nullptr,-1);
    };

    virtual void TearDown(){
        delete t;
    };
};

TEST_F(TimerTest,TimerRunning){
    t->setSec(10);
    t->start();
    ASSERT_TRUE(t->isRunning());
    t->stop();
    ASSERT_FALSE(t->isRunning());
}

TEST_F(TimerTest,TimerNotRunning){
    t->start();
    ASSERT_FALSE(t->isRunning());
}

TEST_F(TimerTest,TimerOutOfRangeS){
    t->setSec(t->getSec()-1);
    ASSERT_EQ(59,t->getSec());
    ASSERT_EQ(59,t->getMin());
    ASSERT_EQ(99,t->getHour());
}

TEST_F(TimerTest,TimerOutOfRangeB){
    t->setSec(60);
    ASSERT_EQ(0,t->getSec());
    ASSERT_EQ(1,t->getMin());
    ASSERT_EQ(0,t->getHour());
}

TEST_F(TimerTest,TimerReset){
    t->setSec(40);
    ASSERT_EQ(40,t->getSec());
    t->reset();
    ASSERT_EQ(0,t->getSec());
    ASSERT_EQ(0,t->getMin());
    ASSERT_EQ(0,t->getHour());
    ASSERT_FALSE(t->isRunning());
}