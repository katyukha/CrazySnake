/* 
 * File:   BaseEventHandler.cpp
 * Author: firemage
 * 
 * Created on 13 лютого 2011, 13:18
 */

#include "BaseEventHandler.h"
#include "Application.h"

BaseEventHandler::BaseEventHandler() {
    Application::sAddHandler(this);
}

/*BaseEventHandler::BaseEventHandler(const BaseEventHandler& orig) {
}*/

BaseEventHandler::~BaseEventHandler() {
    Application::sDelHandler(this);
}
bool BaseEventHandler::on_key(unsigned char key,int x,int y){
        if( key == 27 || key == 'q'){
            Exit();
        }
        return false;
    }

bool BaseEventHandler::on_reshape(int width, int height){
    glViewport (0, 0, (GLsizei)width, (GLsizei)height);//задаємо область просмотру
    glMatrixMode (GL_PROJECTION);//встановлюємо режим матриці видового перетворення на проекціювання
    glLoadIdentity ();//завантажуємо камеру

    gluPerspective (60, (GLfloat)width / (GLfloat)height, 1.0, 100.0);//встановлює матрицю премпективної проекції
    glMatrixMode (GL_MODELVIEW);//перемикаємо матрицю в режим перегляду моделей

}
/*
bool BaseEventHandler::on_display(){
    static GLfloat angle=0;
    glClearColor (0.0,0.0,0.0,1.0);//колір очистки екрану
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//очистка екрану
    glLoadIdentity();//завантаження камери
    gluLookAt (0.0, 0.0, 9.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//звідки і як дивитись
    //далі обертаємо кубик на кут angel по всіх осях
    glRotatef(angle, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    //будуємо куб відповідною стандартною функцією
    glutSolidCube(0.3);

    //cube();//малюємо куб
    glutSwapBuffers();//міняємо буфери місцями
    //angle+=0.6;//змінюємо кут нахилу кубу
    return false;
}*/

class Application;
void BaseEventHandler::Exit(){
    Application::Exit();
}