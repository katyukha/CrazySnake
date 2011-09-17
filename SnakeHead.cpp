/* 
 * File:   SnakeHead.cpp
 * Author: firemage
 * 
 * Created on 22 травня 2011, 22:10
 */

#include "SnakeHead.h"

SnakeHead::SnakeHead(GLfloat x, GLfloat y, GLfloat size):
    SnakeSegment(x,y,size), Timer(50, true){
    dx = dxy;
    dy = 0;
}

void SnakeHead::Time(){
    //move(dx, dy);
    x+=dx;
    y+=dy;
    move(x,y);
}

void SnakeHead::processCollision(CollisionObject* obj){
    SnakeSegment * seg = dynamic_cast<SnakeSegment*>(obj);
    if(!seg){
       return; //collision with  UnKnown Object      
    }
    if(this->contains(seg)){
        delete tail;
        tail = 0;
        //new FreeSegment();
    }else{
        //TODO: move tailed segment to right position in the end of the tail
        toTail(seg);
        new FreeSegment();
    }    
}

bool SnakeHead::on_key(unsigned char key, int x, int y){
    switch(key){
      case 'w': {
            dy = dxy;
            dx = 0;
            break;
        }
        case 'a': {
            dx = -dxy;
            dy = 0;
            break;
        }
        case 'd': {
            dx = dxy;
            dy = 0;
            break;
        }
        case 's': {
            dy = -dxy;
            dx = 0;
            break;
        }
    };
    return false;
}

SnakeHead::SnakeHead(const SnakeHead& orig) {
}

SnakeHead::~SnakeHead() {
}

