#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include "float2.h"
 
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
// Needed on MsWindows
#include <windows.h>
#endif // Win32 platform
 

// Download glut from: 
// http://www.opengl.org/resources/libraries/glut/
#include <GL/freeglut.h>
#include <vector>
#include "Charater.h"
#include "Camera.h"
#include "Brick.h"
#include <iostream>
#include "Scene.h"

using namespace::std;

Scene scene;

float angle = 0.0f;
std::vector<bool>keysPressed;

const int WINDOW_WIDTH = 700;
const int WINDOW_HEIGHT = 500;


float lastGameTime;
float currentGameTime;
float delta_Time;

bool gravity = true;


void onDisplay( ) 
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   
    glLoadIdentity();

    scene.draw();
    glRotatef(angle, 0.4f, 1.0f, 0.0f);
    
    glColor3d(1, 0, 1);
    
	glBegin(GL_LINE_STRIP);
        glVertex3f(0.5f,1.0f, 0.0f);
        glVertex3f( 0.5f, 0.5f, 0.0);
	glEnd();
    
    
	glutSwapBuffers();
}

void onReshape(int WINDOW_WIDTH0, int WINDOW_HEIGHT) 
{
    if (WINDOW_HEIGHT==0) {
        WINDOW_HEIGHT=1;
    }
    float hRatio = 1.0*WINDOW_WIDTH0/WINDOW_HEIGHT;
    
    //Use Projection Matrix
    glMatrixMode(GL_PROJECTION_MATRIX);
    
    //Reset Projection matrix
    glLoadIdentity();
    
    glViewport(0, 0, WINDOW_HEIGHT, WINDOW_HEIGHT);
    
	// Set the correct perspective.
	gluPerspective(45,hRatio,1,1000);
    
	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);}

void onKeyboard(unsigned char key, int x, int y)
{
    keysPressed.at(key)=true;
   glutPostRedisplay();
    
}

void onKeyboardUp(unsigned char key, int x, int y)
{
    keysPressed.at(key) = false;
    
   	glutPostRedisplay();
}

void onIdle( ) {
    // time elapsed since program started, in seconds
    double t = glutGet(GLUT_ELAPSED_TIME) * 0.001;
    // variable to remember last time idle was called
    static double lastTime = 0.0;
    // time difference between calls: time step  
    delta_Time  = t - lastTime;
    // store time
    lastTime = t;
    
    if (delta_Time > 2.5) {
        angle-=1.0f;
    }else{
        angle+=2.0f;
    }
   
    //scene.applyGravity(delta_Time);
    scene.control(keysPressed);
    scene.getCamera().move(delta_Time, keysPressed);
    scene.move(t, delta_Time);
    
    glutPostRedisplay();
}

void mouseClicks(int button, int state, int x, int y) {
    
}


int main(int argc, char *argv[]) {
    
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(
	GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
 
    glutCreateWindow("My First Game");
  
    // Register event handlers here
	glutDisplayFunc(onDisplay);
	glutReshapeFunc(onReshape);
	glutKeyboardFunc(onKeyboard);
	glutKeyboardUpFunc(onKeyboardUp);
	glutIdleFunc(onIdle);
    
    for (int i=0; i<256; i++) {
        keysPressed.push_back(false);
    }
    
    scene.addObject(new Charater);
    scene.addObject(new Brick(float2(0.1, 0.2)));
    scene.addObject(new Brick(float2(-0.05, -0.35)));

    
  //  glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    
    return 0;
}















