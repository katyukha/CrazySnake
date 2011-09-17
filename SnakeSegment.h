/* 
 * File:   SnakeSegment.h
 * Author: firemage
 *
 * Created on 22 травня 2011, 20:39
 */

#ifndef SNAKESEGMENT_H
#define	SNAKESEGMENT_H

#include "BaseEventHandler.h"
#include "CollisionObject.h"

#define dxy 0.1

class SnakeSegment: public BaseEventHandler, public CollisionObject{
protected:
    GLfloat dx, dy;    
    SnakeSegment  * tail, * prev;

    SnakeSegment(const SnakeSegment& orig);
public:
    SnakeSegment(GLfloat x = 0, GLfloat y = 0, GLfloat size = 0.4);
    virtual bool on_display();
    virtual void toTail(SnakeSegment * segment);
    virtual void move(GLfloat new_x, GLfloat new_y);
    bool contains(SnakeSegment * segment);
    virtual ~SnakeSegment();
private:

};

#endif	/* SNAKESEGMENT_H */

