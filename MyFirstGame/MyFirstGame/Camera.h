//
//  Camera.h
//  MyFirstGame
//
//  Created by Yuon Flemming on 11/29/13.
//  Copyright (c) 2013 Yuon Flemming. All rights reserved.
//

#ifndef __MyFirstGame__Camera__
#define __MyFirstGame__Camera__

#include <iostream>
#include "float3.h"
#include "float2.h"
#include "Object.h"
using namespace std;

class Camera {
    
    float velocity; //Used for moving the camera in relation to the player
    float3 eye;
    float3 ahead;
    float3 right;
    float3 up;
    float2 tanFOV;
    
public:
    Camera()
    {
        velocity=0;
        eye = float3(0,0,3);//eye position
        ahead = float3(0,0,-1);
        right = float3(1,0,0);
        up = float3(0,1,0);
        
        tanFOV = float2(0.5,0.5);
    }
        
    void move(double dt, std::vector<bool>& keysPressed);
    void drawModel();
  //  void control(std::vector<bool>& keysPressed, std::vector<Object*>& spawn);

};

#endif /* defined(__MyFirstGame__Camera__) */
