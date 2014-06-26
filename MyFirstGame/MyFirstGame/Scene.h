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
    
public:
    Camera& getCamera()
    {
        return camera;
    }
    
};

