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

// ���������� ������������ ���� ����������� ����������
using namespace glm;
using namespace std;

// ����� ��� ������ C �����
class Mesh
{
public:
	// �����������
	Mesh();
	// �������� ���� �� ����� � ��������� ������
	void load(std::string filename);
	// ����� ���� (�������� ���� ������ � OpenGL)
	void draw();
private:
	struct Vertex
	{
		// �������������� ����������
		GLfloat coord[3];
		// ������ �������
		GLfloat normal[3];
		// ���������� ���������� �������� ����������� ����� 
		GLfloat texCoord[2];
	};

	// ������ ������ ������������� �����
	vector<Vertex> vertices;
	// ������ ��������
	std::vector<GLuint> indices;

	vec3 getVec3(string);
	ivec3* getPolygon(string);

	int indexCount;
	GLuint bufferIds[2];
};