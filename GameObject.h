#pragma once

#include "glew-2.1.0/include/GL/glew.h"
#include <windows.h>

#include <iostream>
#include <memory>
#include <vector>

#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 

#include "GraphicObject.h"
#include "GameObject.h"
#include "Simulation.h"
#include "PhongMaterial.h"
#include "Display.h"

#include "Mesh.h"
#include "Light.h"
#include "camera.h"

// ����� ��� ������������� �������� �������
enum class MoveDirection { STOP, LEFT, RIGHT, UP, DOWN };
class GameObject
{
public:
	// �����������
	GameObject();
	// ��������� ������������� ������������ �������
	// ���������� ����������� ����������� ������� ��� ������������ �������������
	void setGraphicObject(const GraphicObject& graphicObject);
	// ��������� ���������� ��������� (��� ������������� ������ ��� ��������)
	void setPosition(int x, int y);
	void setPosition(ivec2 position);
	// ��������� ������� ���������� ���������
	ivec2 getPosition();
	// ������ �������� � ��������� ����������� � ��������� ���������
	// �������� ������������ ������������ ����������� ������ � �������
	void move(MoveDirection direction, float speed = 3.0f);
	// �������� �� ��, ��� ������ � ��������� ������ ��������
	bool isMoving();
	// ��������� �������� ������� (������� ����������� �������)
	// ����� ���������� ���������� � ������� simulation
	void simulate(float sec);
	// ����� �������� ������� �� �����
	void draw(void);
private:
	// ���������� ���������� �������� �������
	ivec2 position;
	// ����������� ������ (��� ������ �� �����)
	GraphicObject graphicObject;
	// ��������� ������� (�������� ����������� �����������)
	MoveDirection sost;
	// �������� � ����������� (�� 0.0 �� 1.0)
	float progress;
	// �������� �����������
	float speed;

};