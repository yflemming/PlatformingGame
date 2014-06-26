//
//  Object.cpp
//  MyFirstGame
//
//  Created by Yuon Flemming on 11/19/13.
//  Copyright (c) 2013 Yuon Flemming. All rights reserved.
//

#include "Object.h"

void Object::draw(){
    
    glPushMatrix();
        glTranslatef(position.x, position.y, 0.0f);
        drawModel();
    glPopMatrix(); 
}

void Object::applyGravity(float dt){
    float acc = -0.5;
    gravVelocity += acc * dt;
    position.y += gravVelocity * dt;
}

float Object::getObjX(){
    return position.x;
}

float Object::getObjY(){
    return position.y;
}
void Object::detectCollision(Object* object, float lastTime, float _time, float deltaTime){
    
}