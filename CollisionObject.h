/* 
 * File:   CollisionObject.h
 * Author: firemage
 *
 * Created on 23 травня 2011, 0:42
 */

#ifndef COLLISIONOBJECT_H
#define	COLLISIONOBJECT_H

#include <GL/gl.h>

class CollisionObject{
    
    CollisionObject(const CollisionObject& orig);
protected:
    GLfloat x, y, r;
public:
    CollisionObject(GLfloat x = 0, GLfloat y = 0, GLfloat r = 0);
    virtual bool check(CollisionObject * obj);
    virtual void processCollision(CollisionObject * obj){};
    virtual ~CollisionObject();
private:

};


#endif	/* COLLISIONOBJECT_H */

