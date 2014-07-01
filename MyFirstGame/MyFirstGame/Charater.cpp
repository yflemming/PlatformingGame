//
//  Charater.cpp
//  MyFirstGame
//
//  Created by Yuon Flemming on 11/7/13.
//  Copyright (c) 2013 Yuon Flemming. All rights reserved.
//

#include "Charater.h"
#include <GL/freeglut.h>

void Charater::drawModel()
{
    glColor3d(1.0, 0.5, 0.3);
    if (changeOrientation == false){
    
    glPointSize(17);
    glBegin(GL_POINTS);
        glVertex2d(0.024, 0.4);
    glEnd();
        
    glBegin(GL_QUADS);
        glVertex2d(0, 0.23);
        glVertex2d(0, 0.4);
        glVertex2d(0.05, 0.4);
        glVertex2d(0.05, 0.2);
    glEnd();
    
    glBegin(GL_QUAD_STRIP);
        glVertex2d(0.1, 0.2);
        glVertex2d(-0.1, 0.2);
        glVertex2d(0.1, 0.25);
        glVertex2d(-0.1, 0.25);
    glEnd();
        
    } else{
        
    glPointSize(17);
    glBegin(GL_POINTS);
        glVertex2d(0.025, 0.4);
    glEnd();
        
    glBegin(GL_QUADS);
        glVertex2d(0, 0.23);
        glVertex2d(0, 0.4);
        glVertex2d(0.05, 0.4);
        glVertex2d(0.05, 0.2);
    glEnd();
        
    glBegin(GL_QUAD_STRIP);
        glVertex2d(0.1, 0.2);
        glVertex2d(-0.1, 0.2);
        glVertex2d(0.1, 0.25);
        glVertex2d(-0.1, 0.25);
    glEnd();

    }
}

void Charater::move(double t, double dt)
{
    position.x += velocity * dt;
}

void Charater::jump()
{
    //make a cooldown for the jump
    
    for (float time = 0.0; time < airTime; time+=0.01)
    {
        if (time< airTime) {
            position.y += 0.01;
        }
    }
}

void Charater::control(std::vector<bool>& keysPressed, std::vector<Object*>& spawn)
{
    
    if (keysPressed.at('a')) {
        velocity = -1;
        changeOrientation= true;
    }
    else if (keysPressed.at('d'))
    {
        velocity = 1;
        changeOrientation= false;
    }else
        velocity = 0;
}



















