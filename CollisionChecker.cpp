/* 
 * File:   CollisionChecker.cpp
 * Author: firemage
 * 
 * Created on 23 травня 2011, 1:56
 */

#include "CollisionChecker.h"

vector<CollisionObject*> CollisionChecker::objects;
CollisionChecker * CollisionChecker::checker;

CollisionChecker::CollisionChecker(unsigned int time):
                    Timer(time, true){
    if(CollisionChecker::checker)
        throw("Only one collision checker can be created");
    CollisionChecker::checker = this;
}
void CollisionChecker::Time(){
    bool f = true;
    while (f){
      f=false;
      for(vector<CollisionObject*>::iterator i = objects.begin(); i != objects.end(); i++){
        for(vector<CollisionObject*>::iterator j = objects.begin(); j != objects.end(); j++){
            if(i!=j){
                if((*i)->check(*j) || (*j)->check(*i)){
                    f = true;
                    try{
                        bool f = (*i)->processCollision(*j);
                        if( f )
                            (*j)->processCollision(*i);
                    }catch(...){
                    }
                    return;
                }
            }
          }
      }
    }
}
void CollisionChecker::AddObject(CollisionObject* object){
    objects.push_back(object);
}

void CollisionChecker::DelObject(CollisionObject* object){
    for(vector<CollisionObject*>::iterator i = objects.begin(); i != objects.end(); i++)
        if((*i)==object){
            objects.erase(i);
            return;
        }
}
