#pragma once

#include "glew-2.1.0/include/GL/glew.h"
#include <windows.h>

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 
#include <vector>
#include <sstream>  

// используем пространство имен стандартной библиотеки
using namespace glm;
using namespace std;

// КЛАСС ДЛЯ РАБОТЫ C МЕШЕМ
class Mesh
{
public:
	// конструктор
	Mesh();
	// загрузка меша из файла с указанным именем
	void load(std::string filename);
	// вывод меша (передача всех вершин в OpenGL)
	void draw();
private:
	struct Vertex
	{
		// геометрические координаты
		GLfloat coord[3];
		// вектор нормали
		GLfloat normal[3];
		// текстурные координаты нулевого текстурного блока 
		GLfloat texCoord[2];
	};

	// массив вершин полигональной сетки
	vector<Vertex> vertices;
	// массив индексов
	std::vector<GLuint> indices;

	vec3 getVec3(string);
	ivec3* getPolygon(string);

	int indexCount;
	GLuint bufferIds[2];
};