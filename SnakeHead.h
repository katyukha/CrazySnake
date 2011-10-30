/* 
 * File:   SnakeHead.h
 * Author: firemage
 *
 * Created on 22 травня 2011, 22:10
 */

#ifndef SNAKEHEAD_H
#define	SNAKEHEAD_H

#include "SnakeSegment.h"
#include "lib/snakelib.h"

#include <boost/random.hpp>
#include <ctime>

class FreeSegment: public SnakeSegment{
    //static boost::mt11213b stat_rgn
public:
    FreeSegment(){                         // produces randomness out of thin air
        static boost::mt19937 rng(std::time(0));
        boost::uniform_real<> coords(-5,5);
        boost::variate_generator<boost::mt19937&, boost::uniform_real<> >
             rand(rng, coords);
        x = rand();
        y = rand();
        tag = TAG_FREE_SEGMENT;
    }

};

class SnakeHead: public SnakeSegment, public Timer{
    GLfloat dx,dy;

    SnakeHead(const SnakeHead& orig);
public:
    SnakeHead(GLfloat x = 0, GLfloat y = 0, GLfloat size = 0.4);
    void Time();
    virtual ~SnakeHead();
    virtual bool on_key(unsigned char key, int x, int y);
    virtual bool processCollision(CollisionObject * obj);
private:

};

#endif	/* SNAKEHEAD_H */

