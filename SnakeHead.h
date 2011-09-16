/* 
 * File:   SnakeHead.h
 * Author: firemage
 *
 * Created on 22 травня 2011, 22:10
 */

#ifndef SNAKEHEAD_H
#define	SNAKEHEAD_H

#include "SnakeSegment.h"
#include "Timer.h"

//#include <boost/random/uniform_real.hpp>
#include <boost/random.hpp>
//#include <cstdlib>
#include <ctime>

class FreeSegment: public SnakeSegment{
    //static boost::mt11213b stat_rgn
public:
    FreeSegment(){                         // produces randomness out of thin air
        static boost::mt19937 rng(std::time(0));
        boost::uniform_real<> coords(-5,5);
        boost::variate_generator<boost::mt19937&, boost::uniform_real<> >
             rand(rng, coords);
        //boost::variate_generator<boost::mt11213b&, boost::uniform_real<> >
        //     srand(stat_rgn, coords);
        x = rand();
        y = rand();
    }

    /*FreeSegment(GLfloat x, GLfloat y, GLfloat size = 0.4):
                SnakeSegment(x, y, size){}*/
};
//boost::mt11213b FreeSegment::stat_rgn(std::time(0));

class SnakeHead: public SnakeSegment, public Timer{
    GLfloat dx,dy;

    SnakeHead(const SnakeHead& orig);
public:
    SnakeHead(GLfloat x = 0, GLfloat y = 0, GLfloat size = 0.4);
    void Time();
    virtual ~SnakeHead();
    virtual bool on_key(unsigned char key, int x, int y);
    virtual void processCollision(CollisionObject * obj);
private:

};

#endif	/* SNAKEHEAD_H */

