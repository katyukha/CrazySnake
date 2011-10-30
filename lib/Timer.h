/* 
 * File:   Timer.h
 * Author: firemage
 *
 * Created on 13 лютого 2011, 19:28
 */

#ifndef TIMER_H
#define	TIMER_H

#include <map>
#include <GL/glut.h>

class Timer{
    friend void TimerFunc(int value);
    static int id;
    static std::map<int, Timer*> timers;

    int key;            //id of timer
    unsigned int time;           //time range befor call time;
    bool auto_reregister;
    void onTime();
public:
    Timer(unsigned int time = 0, bool auto_reregister = false);

    //derived class should call Time()
    //method of this class to reregister timer
    virtual void Time();
    void reRegister(unsigned int time = 0);
    unsigned int getTime();         //returns timer interval
    virtual ~Timer();
private:

};

#endif	/* TIMER_H */

