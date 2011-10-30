/* 
 * File:   Application.h
 * Author: firemage
 *
 * Created on 30 січня 2011, 21:01
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <string>
#include <vector>

#include "BaseEventHandler.h"
#include "CollisionChecker.h"

class Application{
    friend void display (void);
    friend void reshape (int w, int h);
    friend void KeyFunc(unsigned char key,int x,int y);
    friend void KeyUpFunc(unsigned char key,int x,int y);
    friend void MouseFunc(int button, int state, int x, int y);
    friend void MouseMotionFunc(int x, int y);
    friend void MousePassiveMotionFunc(int x, int y);

    static bool game_mode;
    static bool app_started;
    static Application* app;
    static CollisionChecker * collisionChecker;
    static unsigned int collision_check_timeout;
    std::string game_str;
    std::string title;
    int left,top,width,height;
    int display_mode;
    static std::vector<BaseEventHandler*>  handlers;
    BaseEventHandler * baseHandler;
protected:
    virtual void preDisplay(){};
    virtual void postDisplay();
    virtual void Init();
public:
    Application(int argc, char * argv[], int d_mode = GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    
    virtual ~Application();

    void SetGameMode(std::string game_str= "1024x600:32@75");
    void SetWindowMode(std::string title = "GL Application", int top = 0, int left = 0, int width = 500, int height = 500);
    void AddHandler(BaseEventHandler * handler);
    void DelHandler(BaseEventHandler * handler);
    void SetCollisionTimeout(unsigned int timeout){ collision_check_timeout = timeout; }

    virtual void Start();

    static void Exit();
    static bool isGameMode(){ return game_mode; }
    static void sAddHandler(BaseEventHandler * handler);
    static void sDelHandler(BaseEventHandler * handler);
};

#endif	/* APPLICATION_H */

