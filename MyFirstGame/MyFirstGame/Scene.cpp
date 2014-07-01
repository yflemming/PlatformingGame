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

#include "Scene.h"



