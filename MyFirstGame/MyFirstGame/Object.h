//
//  Object.h
//  MyFirstGame
//
//  Created by Yuon Flemming on 11/19/13.
//  Copyright (c) 2013 Yuon Flemming. All rights reserved.
//

#ifndef __MyFirstGame__Object__
#define __MyFirstGame__Object__

#include <iostream>
#include "float2.h"
#include <GLUT/GLUT.h>
#include "BoundingBox.h"
#include <vector>


class Object
{
    protected:
        float2 position;
        float velocity;
        float gravVelocity;
        BoundingBox boundingBox = *new BoundingBox(
                                                  position.y+0.3,
                                                  position.y-0.3,
                                                  position.x-0.2,
                                                  position.x+0.2
                                                  );
    public:
    
        virtual ~Object(){}
        virtual void draw();
        virtual void drawModel()=0;
        virtual void applyGravity(float dt);
        virtual void detectCollision(Object* object, float lastTime, float _time, float deltaTime);
    
        virtual float getObjX();
        virtual float getObjY();
        
        Object* translate(float2 offset)
        {
            position += offset; return this;
        }
    
        virtual void move(double t, double dt){}
        virtual void control(std::vector<bool>& keysPressed, std::vector<Object*>& spawn){}
    
};

#endif /* defined(__MyFirstGame__Object__) */
