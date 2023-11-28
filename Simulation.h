#pragma once
#include "glew-2.1.0/include/GL/glew.h"
#include <windows.h>

#include "GL/freeglut.h"
#include <glm/glm.hpp>

#include <ctime>

void simulation();
void mouseWheel(int, int, int, int);
void movePlayer();