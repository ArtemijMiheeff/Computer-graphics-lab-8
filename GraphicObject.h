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

#include "Mesh.h"
#include "PhongMaterial.h"
using namespace glm;
// ����� ��� ������������� ������ ������������ �������
class GraphicObject
{
public:
	// �����������
	GraphicObject();
	// ��������� � ��������� ������� �������
	void setPosition(vec3 position);
	vec3 getPosition();
	// ��������� � ��������� ���� �������� � ��������
	// ������� �������������� � �������������� ��������� 
	// ������ ��� Oy �� ������� �������
	void setAngle(float grad);
	float getAngle();
	// ��������� �������� ����� �������
	void set�olor(vec3 color);
	vec3 getColor();
	// ��������� ������������� ���������
	void setMaterial(std::shared_ptr<PhongMaterial> material);
	// ��������� ������������� ����
	void setMesh(std::shared_ptr<Mesh> mesh);
	// ������� ������
	void draw();

private:
	// ������� ������� � ���������� ������� ���������
	vec3 position;
	// ���� �������� � �������������� ��������� (� ��������)
	float angle;
	// ���� ������
	vec3 color;
	// ������� ������ - ���� �� ��������� ������ ���
	GLfloat modelMatrix[16] =
	{
		1.0, 0.0, 0.0, 0.0, // ��� Ox
		0.0, 1.0, 0.0, 0.0, // ��� Oy
		0.0, 0.0, 1.0, 0.0, // ��� Oz
		0.0, 0.0, 0.0, 1.0
	};
	std::shared_ptr<PhongMaterial> material;
	// ������������ ���
	std::shared_ptr<Mesh> mesh;
private:
	// ������ ������� modelMatrix �� ������ position � angle
	void recalculateModelMatrix();

};
