/* 
 * File:   BaseEventHandler.h
 * Author: firemage
 *
 * Created on 13 лютого 2011, 13:18
 */

#ifndef BASEEVENTHANDLER_H
#define	BASEEVENTHANDLER_H

//#include "Application.h"
#include <GL/gl.h>
#include <GL/glut.h>

class BaseEventHandler {
public:
    BaseEventHandler();
    //BaseEventHandler(const BaseEventHandler& orig);
    virtual ~BaseEventHandler();

    //all event handlers should return true if event is handled.
    //this means that no other handlers will be applied to this event
    virtual bool on_display(){return false;};
    virtual bool on_idle(){return false;};
    virtual bool on_reshape(int width, int height);//{return false;};
    virtual bool on_key(unsigned char key,int x,int y);                    
    virtual bool on_key_up(unsigned char key,int x,int y){return false;};
    virtual bool on_mouse_motion(int x,int y){return false;}
    virtual bool on_mouse_passive_motion(int x, int y){return false;}
    virtual bool on_mouse(int button, int state, int x, int y){return false;}

    void Exit();
};

#endif	/* BASEEVENTHANDLER_H */

