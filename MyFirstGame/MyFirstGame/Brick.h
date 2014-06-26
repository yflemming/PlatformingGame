//
//  Brick.h
//  MyFirstGame
//
//  Created by Yuon Flemming on 2/1/14.
//  Copyright (c) 2014 Yuon Flemming. All rights reserved.
//

#ifndef MyFirstGame_Brick_h
#define MyFirstGame_Brick_h


#include <iostream>
#include <GLUT/glut.h>
#include "Object.h"
#include "float2.h"


class Brick: public Object {
    
public:
    Brick(float2 location){
        gravVelocity=0;
        position = location;
    };
    
    void drawModel(){
        glColor3d(0.8,0.8,0.8);
        glBegin(GL_QUAD_STRIP);
            glVertex2d(position.x-0.1, position.y+0.1);
            glVertex2d(position.x-0.1, position.y-0.1);
            glVertex2d(position.x+0.1, position.y+0.1);
            glVertex2d(position.x+0.1, position.y-0.1);
        glEnd();
    }
    void applyGravity(float dt){
        
    }
    void move(double t, double dt){
        
    }
};


#endif /* defined(__MyFirstGame__Brick__) */

