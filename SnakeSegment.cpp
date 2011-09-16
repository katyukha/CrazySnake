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
    tail = 0;
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
    glTranslatef(x,y,0);//встановлюємо зміщення локальної системи координат    
    glutSolidSphere(r, 50, 50);
    //переміщуємо куб згідно з обраним прискоренням
    //x+=dx;y+=dy;
    //angle+=0.3;//змінюємо кут нахилу кубу
  
    
    //  glutSwapBuffers();//міняємо буфери місцями
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
    if(this->tail)
        this->tail->toTail(segment);
    else{
        this->tail = segment;
    }
}

bool SnakeSegment::contains(SnakeSegment* segment){
    if(this==segment)
        return true;
    if(tail)
        return tail->contains(segment);
    return false;
}
