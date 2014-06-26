//
//  stage.h
//  MyFirstGame
//
//  Created by Yuon Flemming on 11/19/13.
//  Copyright (c) 2013 Yuon Flemming. All rights reserved.
//

#ifndef __MyFirstGame__stage__
#define __MyFirstGame__stage__

#include <iostream>
#include "Object.h"

#endif /* defined(__MyFirstGame__stage__) */

class stage: public Object {
    
public:
    stage(){
        gravVelocity=0;
    };
    
    void drawModel();
    void applyGravity(float dt);
    void move(double t, double dt);
};