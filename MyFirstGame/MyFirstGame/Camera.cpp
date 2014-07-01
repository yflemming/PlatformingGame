//
//  Camera.cpp
//  MyFirstGame
//
//  Created by Yuon Flemming on 11/29/13.
//  Copyright (c) 2013 Yuon Flemming. All rights reserved.
//

#include "Camera.h"
#include <GL/freeglut.h>

void Camera::drawModel()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(atan(tanFOV.y)*2/3.14*180, tanFOV.x/tanFOV.y, 0.1, 500);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
              eye.x, eye.y, eye.z, eye.x+ahead.x,
              eye.y+ahead.y, eye.z+ahead.z,
              0, 1, 0);
  //std::cout<<"in camera draw model: "<<eye.x<<" "<<eye.y<<std::endl;
}

void Camera::move(double dt, std::vector<bool>& keysPressed)
{
  //  std::cout<<"After camera move call"<<eye.x<<" "<<eye.y<<std::endl;
    
    if (keysPressed.at('a'))
    {
        eye -= right*dt;
    }
    if (keysPressed.at('d'))
    {
        eye += right*dt;
    }
}

