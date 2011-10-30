/* 
 * File:   Timer.cpp
 * Author: firemage
 * 
 * Created on 13 лютого 2011, 19:28
 */

#include "Timer.h"

int Timer::id=0;
std::map<int, Timer*> Timer::timers;

void TimerFunc(int value);
Timer::Timer(unsigned int time, bool auto_reregister) {
    this->auto_reregister = auto_reregister;
    timers[id]=this;
    key = id;
    this->time = time;
    if (time != 0){
        glutTimerFunc(time,TimerFunc,id);
    }

    id++;
}

Timer::~Timer() {
    timers.erase(key);
}

void Timer::onTime(){
    Time();
    if(auto_reregister)
        reRegister();
}

void Timer::Time(){
    //reRegister();
}

void Timer::reRegister(unsigned int time){
    if (time!=0)
        this->time = time;
    glutTimerFunc(this->time, TimerFunc, key);
}

unsigned int Timer::getTime(){
    return time;
}

void TimerFunc(int value){
    try{
        Timer::timers[value]->onTime();
    }catch(...){
        //do nothing if no timer with given id (value)
    }
}