//
//  Charater.h
//  MyFirstGame
//
//  Created by Yuon Flemming on 11/7/13.
//  Copyright (c) 2013 Yuon Flemming. All rights reserved.
//

#ifndef __MyFirstGame__Charater__
#define __MyFirstGame__Charater__

#include <iostream>
#include "Charater.h"
#include "float2.h"
#include "Object.h"

class Charater: public Object
{
    float gravity = 0.001;
    float airTime = 0.1;
    int health;
    void drawModel();
    void move(double t, double dt);

public:
    
    Charater()
    {
        velocity=0;
    }
    
    void jump();
    bool changeOrientation = false;
    void control(std::vector<bool>& keysPressed, std::vector<Object*>& spawn);
    
};
#endif /* defined(__MyFirstGame__Charater__) */
