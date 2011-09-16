/* 
 * File:   Cube.cpp
 * Author: firemage
 * 
 * Created on 13 лютого 2011, 15:37
 */

#include "Cube.h"


GLfloat Cube::dxy=0.009;
Cube::Cube() : Timer(50, true) {
    x = 0;
    y = 0;
    angle = 0;
}

bool Cube::on_key(unsigned char key, int x, int y){
    switch(key){
      case 'w': {
            dy+=dxy;
            break;
        }
        case 'a': {
            dx-=dxy;
            break;
        }
        case 'd': {
            dx+=dxy;
            break;
        }
        case 's': {
            dy-=dxy;
            break;
        }
    };
    return false;
}

bool Cube::on_key_up(unsigned char key, int x, int y){
    switch(key){
      case 'w': {
            dy-=dxy;
            break;
        }
        case 'a': {
            dx+=dxy;
            break;
        }
        case 'd': {
            dx-=dxy;
            break;
        }
        case 's': {
            dy+=dxy;
            break;
        }
    };
    return false;
}


bool Cube::on_display(){
     glClearColor (0.0,0.0,0.0,1.0);//колір очистки екрану
     glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//очистка екрану
     glLoadIdentity();//завантаження камери
     gluLookAt (0.0, 0.0, 9.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//звідки і як дивитись

     Draw();

     glutSwapBuffers();//міняємо буфери місцями
     

     return false;
}

void Cube::Draw(){
    glTranslatef(x,y,0);//встановлюємо зміщення локальної системи координат
    //далі обертаємо кубик на кут angel по всіх осях
    glRotatef(angle, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    //будуємо куб відповідною стандартною функцією
    glutSolidCube(0.4);
    //переміщуємо куб згідно з обраним прискоренням
    x+=dx;y+=dy;
    angle+=0.3;//змінюємо кут нахилу кубу
}

bool Cube::on_mouse(int button, int state, int x, int y){
   //
}

void Cube::Time(){
    static float old_x, old_y;
    old_x = x;
    old_y = y;
    //x+=dxy;
    //y+=dxy;
    /*x += dx;
    y += dy;
    angle += 1.50;*/
    //Timer::Time();
}