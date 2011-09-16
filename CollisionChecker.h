/* 
 * File:   CollisionChecker.h
 * Author: firemage
 *
 * Created on 23 травня 2011, 1:56
 */

#ifndef COLLISIONCHECKER_H
#define	COLLISIONCHECKER_H

#include "Timer.h"
#include "CollisionObject.h"
#include <vector>
using namespace std;

class CollisionChecker: public Timer{
    static vector<CollisionObject*> objects;
    static CollisionChecker * checker;
    void Time();
public:
    CollisionChecker(unsigned int time);
    static void AddObject(CollisionObject * object);
    static void DelObject(CollisionObject * object);
};

#endif	/* COLLISIONCHECKER_H */

