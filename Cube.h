/* 
 * File:   Cube.h
 * Author: firemage
 *
 * Created on 13 лютого 2011, 15:37
 */

#ifndef CUBE_H
#define	CUBE_H

#include "BaseEventHandler.h"
#include "Timer.h"

class Cube : public BaseEventHandler, Timer{
private:
    GLfloat x, y, dx, dy;        //position
    GLfloat angle;      //angel
    static GLfloat dxy;
public:
    Cube();
    /*Cube(const Cube& orig);
    virtual ~Cube();*/

    virtual void Draw();
    virtual bool on_display();
    virtual bool on_key(unsigned char key, int x, int y);
    virtual bool on_key_up(unsigned char key, int x, int y);
    virtual bool on_mouse(int button, int state, int x, int y);
    virtual void Time();
};

#endif	/* CUBE_H */

