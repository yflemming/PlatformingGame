//
//  BoundingBox.h
//  MyFirstGame
//
//  Created by Yuon Flemming on 12/24/13.
//  Copyright (c) 2013 Yuon Flemming. All rights reserved.
//

#pragma once

#include <iostream>
#include "Object.h"

class BoundingBox
{
public:
    bool _collisionTop = false;
    bool _collisionBot = false;
    bool _collisionLft = false;
    bool _collisionRgh = false;
    
    float _top;
    float _bottom;
    float _left;
    float _right;

    BoundingBox()
    {
        _top = 0.0f;
        _bottom = 0.0f;
        _left = 0.0f;
        _right = 0.0f;
    }
    
    void boxOverLap(BoundingBox objBox1, BoundingBox objBox2){
        if (objBox1._top==objBox2._bottom)
        {
            objBox1._collisionTop = true;
            objBox2._collisionBot = true;
        }
        
        if (objBox1._bottom==objBox2._top)
        {
            objBox1._collisionBot = true;
            objBox2._collisionTop = true;
        }
        
        if (objBox1._left==objBox2._right)
        {
            objBox1._collisionLft = true;
            objBox2._collisionRgh = true;
        }
        
        if (objBox1._right==objBox2._left)
        {
            objBox1._collisionRgh = true;
            objBox2._collisionLft = true;
        }
    }
    
    BoundingBox(float _top, float _bottom, float _left, float _right):_top(_top),_bottom(_bottom),_left(_left),_right(_right){}
    
    
};




