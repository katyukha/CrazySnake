/* 
 * File:   main.cpp
 * Author: firemage
 *
 * Created on 30 січня 2011, 20:25
 */

#include <cstdlib>
#include "snakelib.h"
#include "SnakeSegment.h"
#include "SnakeHead.h"

/*
 * 
 */

class MyApp : public Application{
protected:
    void preDisplay(){
        glClearColor (0.0,0.0,0.0,1.0);//колір очистки екрану
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//очистка екрану
        glLoadIdentity();//завантаження камери
        gluLookAt (0.0, 0.0, 9.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//звідки і як дивитись
    }
    /*void postDisplay(){
         glutSwapBuffers();//міняємо буфери місцями
    }*/
    void Init(){
        Application::Init();
        //AddHandler(new BaseEventHandler()); //base handler to handle exit
        new BaseEventHandler();
        SnakeHead * head = new SnakeHead();
        //AddHandler(head);

        for(GLfloat x=-1; -x/1<7; x-=1)
            head->toTail(new SnakeSegment(x, 0, 0.4));
/*
        SnakeSegment * seg = new SnakeSegment(-0.75,0,0.4);
        //AddHandler(seg);
        head->toTail(seg);
        
        seg = new SnakeSegment(-1.5,0,0.4);
        //AddHandler(seg);
        head->toTail(seg);

        seg = new SnakeSegment(-3.5,0,0.4);
        //AddHandler(seg);
        head->toTail(seg);

        seg = new SnakeSegment(-5.5,0,0.4);
        //AddHandler(seg);
        head->toTail(seg);

        seg = new SnakeSegment(-7.5,0,0.4);
        //AddHandler(seg);
        head->toTail(seg);

        seg = new SnakeSegment(-9.5,0,0.4);
        //AddHandler(seg);
        head->toTail(seg);

        seg = new SnakeSegment(-11.5,0,0.4);
        //AddHandler(seg);
        head->toTail(seg);
*/
        new FreeSegment();
        //seg = new FreeSegment();


    }
public:
    MyApp(int argc, char** argv):Application(argc, argv){

    }
};

int main(int argc, char** argv) {

    MyApp app(argc, argv);
    app.SetWindowMode("test app", 0,0,700,300);
    app.Start();
    return 0;
}

