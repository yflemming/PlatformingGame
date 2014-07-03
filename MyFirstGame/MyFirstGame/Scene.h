#pragma once

#include "Object.h"
#include "Camera.h"

class Scene
{
    Camera camera;
    std::vector<Object*> objects;
    
public:
    void addObject(Object* object) {
        objects.push_back(object);
    }
    ~Scene()
    {
        for(unsigned int i=0; i<objects.size(); i++)
            delete objects.at(i); 
    }
    
    void draw()
    {
        camera.drawModel();
        for(unsigned int i=0; i<objects.size(); i++)
            objects.at(i)->draw();
    }
    
    void move(double t, double dt)
    {
        for(unsigned int i=0; i<objects.size(); i++)
            objects.at(i)->move(t, dt);
    }
    
    void applyGravity(double dt)
    {
        for(unsigned int i=0; i<objects.size(); i++)
            objects.at(i)->applyGravity(dt);
    }
    
    //void checkBoundingBox

    
    void control(std::vector<bool>& keysPressed)
    {
		std::vector<Object*> spawn;
        for(unsigned int i=0; i<objects.size(); i++)
            objects.at(i)->control(keysPressed, spawn);
                objects.insert(objects.end(),
                        spawn.begin(), spawn.end());
    }

	void detectCollision()
	{
		BOOL quadI = FALSE;
		BOOL quadII = FALSE;
		BOOL quadIII = FALSE;
		BOOL quadIV = FALSE;

		for (unsigned int i = 0; i < objects.size(); i++)
		{
			//determine quad of obj.at(i), either I, II, III or IV, relative to eye position of camera

			if (objects.at(i).position.x >= camera.eye.x && objects.at(i).position.y >= camera.eye.y){
				quadI = TRUE
			}
			if (objects.at(i).position.x <= camera.eye.x && objects.at(i).position.y >= camera.eye.y){
				quadII = TRUE
			}
			if (objects.at(i).x <= camera.eye.x && objects.at(i).position.y <= camera.eye.y){
				quadIII = TRUE
			}
			if (objects.at(i).x >= camera.eye.x && objects.at(i).position.y <= camera.eye.y){
				quadIV = TRUE
			}

			for (unsigned int j = 0; i < objects.size(); j++)
			{
				/*
				1. Check quadrent of second object, see if is in same as the first
				2. If first and second object are in same quad, check the location of bounding box overlap
				3. If boxes overlap, based on location of collision, change position of object 1 
				*/
				if ()
				{

				}
			}
		}
	}
    
public:
    Camera& getCamera()
    {
        return camera;
    }
    
};

