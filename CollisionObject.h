/* 
 * File:   CollisionObject.h
 * Author: firemage
 *
 * Created on 23 травня 2011, 0:42
 */

#ifndef COLLISIONOBJECT_H
#define	COLLISIONOBJECT_H

#include <GL/gl.h>
#include <CollisionTags.h>

class CollisionObject{
    
    CollisionObject(const CollisionObject& orig);
protected:
    GLfloat x, y, r;
public:
    int tag;

    CollisionObject(GLfloat x = 0, GLfloat y = 0, GLfloat r = 0);

    virtual bool check(CollisionObject * obj);

    // If false returned then no call to other_obj->processCollision will be made
    virtual bool processCollision(CollisionObject * obj){return true;}

    virtual ~CollisionObject();
private:

};


#endif	/* COLLISIONOBJECT_H */

