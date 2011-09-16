/* 
 * File:   Application.cpp
 * Author: firemage
 * 
 * Created on 30 січня 2011, 21:01
 */

#include "Application.h"
#include <iostream>

bool Application::app_started;
bool Application::game_mode;
Application* Application::app;
std::vector<BaseEventHandler*>  Application::handlers;
CollisionChecker* Application::collisionChecker;
unsigned int Application::collision_check_timeout;
Application::Application(int argc, char * argv[], int d_mode) {
    display_mode = d_mode;
    if(app_started)
        throw "Application has been already started";
    
    app_started = true;
    collision_check_timeout = 70;
    //app = this;
    glutInit (&argc, argv);
}

Application::~Application() {
    //delete baseHandler;
    //for(int i = 0; i<handlers.size();i++)
    //    delete handlers[i];
}


//Start OpenGL Application
void display (void);
void reshape (int w, int h);
void KeyFunc(unsigned char key,int x,int y);
void KeyUpFunc(unsigned char key,int x,int y);
void MouseFunc(int button, int state, int x, int y);
void MouseMotionFunc(int x, int y);
void MousePassiveMotionFunc(int x, int y);
void Application::Start(){       

    app = this;

    glutInitDisplayMode(this->display_mode);
    if(game_mode){
        glutGameModeString(game_str.c_str());//встановлюємо ігровий режим
        glutEnterGameMode();//вхожимо в нього
    }else{
    glutInitWindowSize (width, height);//ініціалізуємо вікно
    glutInitWindowPosition (left, top);//встановлюємо позицію вікна
    glutCreateWindow (title.c_str());//створюємо вікно
    }
    
    Init();     //call initialization of application

    /*
     * Application must have base handler that will giv ability to exit from application.
     * Some handlers have to be created in Init Function.
    */
    if(handlers.empty()){
        baseHandler = new BaseEventHandler();
        //handlers.push_back(baseHandler);
    }

    collisionChecker = new CollisionChecker(collision_check_timeout);

    glutDisplayFunc (display);//встановлюємо функцію дисплею
    glutIdleFunc (display);//встановлюємо функцію стану idle
    glutReshapeFunc (reshape);//встановлюємо функцію-обробник зміни форми
    glutKeyboardFunc(KeyFunc);//встановлюємо клавіатурну функцію
    glutKeyboardUpFunc(KeyUpFunc);
    glutMouseFunc(MouseFunc);
    glutMotionFunc(MouseMotionFunc);
    glutPassiveMotionFunc(MousePassiveMotionFunc);

    glutMainLoop ();//запуск головного циклу....

}

void Application::Init(){
    glEnable (GL_DEPTH_TEST);//вмикаємо перевірку глибини
    glEnable (GL_LIGHTING);//вмикаємо освітлення
    glEnable (GL_LIGHT0);//вмикаємо нульове джерело світлo
}

void Application::SetGameMode(std::string game_str){
    game_mode = true;
    this->game_str=game_str;
}

void Application::SetWindowMode(std::string title, int top, int left, int width, int height){
    game_mode = false;
    this->title = title;
    this->top = top;
    this->left = left;
    this->width = width;
    this->height = height;
}

void Application::AddHandler(BaseEventHandler* handler){
    handlers.push_back(handler);
}

void Application::sAddHandler(BaseEventHandler* handler){
    //handlers.push_back(handler);
    app->AddHandler(handler);

}

void Application::DelHandler(BaseEventHandler* handler){
    for(std::vector<BaseEventHandler*>::iterator i = handlers.begin(); i != handlers.end(); i++){
        if((*i)==handler){
            handlers.erase(i);
            return;
        }
    }

    /*for(int i = 0; i<handlers.size();i++)
        if(handler == handlers[i])
            //delete handlers[i];
     */
}

void Application::sDelHandler(BaseEventHandler* handler){
    app->DelHandler(handler);
}

void Application::postDisplay(){
    glutSwapBuffers();//міняємо буфери місцями
}

void Application::Exit()
{
        if(game_mode){
            glutLeaveGameMode();
        }
        //delete app;
        for(int i = 0; i<handlers.size();i++)
            delete handlers[i];
        exit(0);

}

//OpenGL Handlers
void display (void){
    //std::cout << Application::app << std::endl;
    if(Application::app)
        Application::app->preDisplay();
    for(int i = Application::handlers.size()-1;i>=0;i--)
        if( Application::handlers[i]->on_display())
            break;
    if(Application::app)
        Application::app->postDisplay();
}

void reshape (int w, int h) {
    for(int i = Application::handlers.size()-1;i>=0;i--)
        if( Application::handlers[i]->on_reshape(w, h))
            break;
}

void KeyFunc(unsigned char key,int x,int y){
    for(int i = Application::handlers.size()-1;i>=0;i--)
        if( Application::handlers[i]->on_key(key, x, y))
            break;
}

void KeyUpFunc(unsigned char key,int x,int y){
    for(int i = Application::handlers.size()-1;i>=0;i--)
        if( Application::handlers[i]->on_key_up(key, x, y))
            break;
}

void MouseFunc(int button, int state, int x, int y){
    for(int i = Application::handlers.size()-1;i>=0;i--)
        if( Application::handlers[i]->on_mouse(button, state, x, y))
            break;
}

void MouseMotionFunc(int x, int y){
    for(int i = Application::handlers.size()-1;i>=0;i--)
        if( Application::handlers[i]->on_mouse_motion(x, y))
            break;
}

void MousePassiveMotionFunc(int x, int y){
    for(int i = Application::handlers.size()-1;i>=0;i--)
        if( Application::handlers[i]->on_mouse_passive_motion(x, y))
            break;
}