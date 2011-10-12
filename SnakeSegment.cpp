/* 
 * File:   SnakeSegment.cpp
 * Author: firemage
 * 
 * Created on 22 травня 2011, 20:39
 */

#include "SnakeSegment.h"
#include "SnakeHead.h"
#include <cmath>
#include <iostream>

SnakeSegment::SnakeSegment(GLfloat x, GLfloat y, GLfloat size) {
    this->x=x;
    this->y=y;
    this->r = size;
    this->tag = TAG_SNAKE_SEGMENT;
    tail = 0;
    prev = 0;
    dx = 0;
    dy = 0;
}

SnakeSegment::SnakeSegment(const SnakeSegment& orig) {
}

SnakeSegment::~SnakeSegment() {
    if(tail){
        delete tail;
        tail = 0;
    }
}

bool SnakeSegment::on_display(){
    glPushMatrix();
    glTranslatef(x,y,0);
    glutSolidSphere(r, 50, 50);
    glPopMatrix();
    return false;
}

void SnakeSegment::move(GLfloat new_x, GLfloat new_y){
    if(new_x != x || new_y != y){
        float dx_ = (new_x - x);
        float dy_ = (new_y - y);
        float dist_ = std::sqrt(dx_*dx_+dy_*dy_);
        float cos_ = std::abs(dx_)/dist_;        
        float dx_1 = cos_*1;
        float sin_ = std::abs(dy_)/dist_;        
        float dy_1 = sin_*1;        
        x = new_x + dx_1*((dx_>0)?-1:1);
        y = new_y + dy_1*((dy_>0)?-1:1);
    }

    if(tail)
        tail->move(x,y);    
}

void SnakeSegment::toTail(SnakeSegment* segment){
    if(!segment) return;
    if(this->tail)
        this->tail->toTail(segment);
    else{
        this->tail = segment;
        segment->prev = this;
        if( this->prev ){
            segment->x = this->x + (this->x - this->prev->x);
            segment->y = this->y + (this->y - this->prev->y);
        }
    }
}

bool SnakeSegment::contains(SnakeSegment* segment){
    if(this==segment)
        return true;
    if(tail)
        return tail->contains(segment);
    return false;
}

bool SnakeSegment::processCollision(CollisionObject* obj){
    if( obj->tag == TAG_FREE_SEGMENT ){
        this->toTail( (SnakeSegment*)obj);
        obj->tag = TAG_SNAKE_SEGMENT;
        new FreeSegment();
        return false;
    }
    
    if( obj->tag == TAG_SNAKE_SEGMENT && this->tag == TAG_SNAKE_SEGMENT ){
        std::cout << "Hello!!!" << std::endl;
        SnakeSegment * seg = static_cast<SnakeSegment *>(obj);
        while(seg->tag != TAG_SNAKE_HEAD){
            seg = seg->prev;
        }
        delete seg->tail;
        return false;
    }

/*
    if( obj->tag == TAG_SNAKE_HEAD)
        return;
    
    SnakeSegment * seg  =  dynamic_cast<SnakeSegment*>(obj);


    if(!seg){
       return; //collision with  UnKnown Object      
    }

    if (!seg->prev and seg->tail)   //if it is head
       return;

    //FreeSegment  * fseg =  dynamic_cast<FreeSegment*>(obj);
    if(seg  &&  !seg->tail  &&  !seg->prev){          // if it is free segment
       this->toTail(seg);
       return;
    }
    return;

    SnakeSegment * t= this->prev;
    bool f = false;
    while(t && !dynamic_cast<SnakeHead*>(t)){
         if( !t->prev ) 
             break;
         t = t->prev;
         if( t == obj )
            f = true;
    }

    SnakeHead * head = dynamic_cast<SnakeHead*>(t);
    if (!head)
         return;
    if (head->contains(seg)){
          delete head->tail;
    }
    */
}
