#pragma once
#include "glew-2.1.0/include/GL/glew.h"
#include <windows.h>

#include <stdio.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <fstream>
#include <string>
#include <sstream>
using namespace glm;
using namespace std;
class PhongMaterial
{
public:
	// ����������� �� ���������
	PhongMaterial();
	// ������� ���������� ���������
	void setAmbient(vec4 color);
	void setDiffuse(vec4 color);
	void setSpecular(vec4 color);
	void setEmission(vec4 color);
	void setShininess(float p);
	//float getFloat(string line);
	//vec4 getVec4(string line);
	// �������� ���������� ��������� �� �������� ���������� �����
	void load(std::string filename);
	// ��������� ���� ���������� ���������
	void apply();
private:
	// ������� ������������ 
	vec4 ambient;
	// ��������� ������������
	vec4 diffuse;
	// ���������� ������������
	vec4 specular;
	// ������������
	vec4 emission;
	// ������� ����������������
	float shininess;
};