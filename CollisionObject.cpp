/* 
 * File:   CollisionObject.cpp
 * Author: firemage
 * 
 * Created on 23 травня 2011, 0:42
 */

#include "CollisionObject.h"
#include "CollisionChecker.h"
#include <cmath>

class CollisionChecker;
CollisionObject::CollisionObject(GLfloat x, GLfloat y, GLfloat r){
    this->x = x;
    this->y = y;
    this->r = r;
    CollisionChecker::AddObject(this);
}

bool CollisionObject::check(CollisionObject* obj){
    // returns true if there is a collision of this and obj.
    float dist = std::sqrt((x-obj->x)*(x-obj->x)+(y-obj->y)*(y-obj->y) );
    if(dist<(r+obj->r))
        return true;
    return false;
}

CollisionObject::CollisionObject(const CollisionObject& orig) {
}

CollisionObject::~CollisionObject() {
    CollisionChecker::DelObject(this);
}
