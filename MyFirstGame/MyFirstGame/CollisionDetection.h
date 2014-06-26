//
//  CollisionDetection.h
//  MyFirstGame
//
//  Created by Yuon Flemming on 3/25/14.
//  Copyright (c) 2014 Yuon Flemming. All rights reserved.
//

#ifndef MyFirstGame_CollisionDetection_h
#define MyFirstGame_CollisionDetection_h

#include "Object.h"
#include "Character.h"
#include "BoundingBox.h"
#include "float2.h"
#include "Brick.h"

class CollisionDetection {
    
    
public:
    bool collideTop = FALSE;
    bool collideBottom = FALSE;
    bool collideLeft = FALSE;
    bool collideRight = FALSE;
    
    CollisionDetection(Object activeObject, Object collisionObject){
        
    }
    
    
};

#endif
