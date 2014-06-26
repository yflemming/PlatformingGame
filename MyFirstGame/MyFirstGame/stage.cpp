//
//  stage.cpp
//  MyFirstGame
//
//  Created by Yuon Flemming on 11/19/13.
//  Copyright (c) 2013 Yuon Flemming. All rights reserved.
//

#include "stage.h"
#include <GLUT/glut.h>


void stage::drawModel()
{
    glColor3d(0.5, 0.5, 0.5);
    
    glAlphaFunc(1, 1);
    
    glBegin(GL_QUAD_STRIP);
    glVertex2d(-1, -0.1);
    glVertex2d(-1, -0.3);
    glVertex2d(1, -0.1);
    glVertex2d(1, -0.3);
    glEnd();
    glBegin(GL_QUAD_STRIP);
    glVertex2d(-1, 1);
    glVertex2d(-1, 0.8);
    glVertex2d(1, 1);
    glVertex2d(1, 0.8);
    glEnd();
    glBegin(GL_QUAD_STRIP);
    glVertex2d(-1, 0.8);
    glVertex2d(-1, -0.1);
    glVertex2d(-0.8, 0.8);
    glVertex2d(-0.8, -0.1);
    glEnd();
    glBegin(GL_QUAD_STRIP);
    glVertex2d(1, 0.8);
    glVertex2d(1, -0.1);
    glVertex2d(0.8, 0.8);
    glVertex2d(0.8, -0.1);
    glEnd();
}

void stage::move(double t, double dt){

}

void stage::applyGravity(float dt){
    
}