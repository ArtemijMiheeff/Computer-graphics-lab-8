#include <windows.h>
#include <iostream>
#include <memory>
#include <vector>
#include "glew-2.1.0/include/GL/glew.h"
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
#include "Data.h"
#include "Mesh.h"
#include "Light.h"
#include "camera.h"

// ���������� ������������ ���� ����������� ����������
using namespace glm;
using namespace std;

// �������, ���������� ��� ��������� �������� ����
void reshape(int w, int h)
{
	// ���������� ����� ������� ���������, ������ ���� ������� ����
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	// ���������� ������� �������� � ���������� ��������
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (float)w / h, 0.2, 70.0);
};

// ������� ���������� ��� ����������� ����
// � ��� ����� � �������������, �� �������� glutPostRedisplay

//void display(void)
//{
//	
//	// �������� ����� ����� � ����� �������
//	glClearColor(0.00, 0.00, 0.00, 1.0);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	// �������� ���� �������
//	glEnable(GL_DEPTH_TEST);
//	// ������������� ������
//	//glMatrixMode(GL_MODELVIEW);
//	//glLoadIdentity();
//	camera.apply();
//	/*material.setDiffuse(vec4(0.0, 0.0, 1.0, 1.0));
//	material.setAmbient(vec4(0.0, 0.0, 0.4, 1.0));
//	material.setSpecular(vec4(1.0, 1.0, 1.0, 0.0));
//	material.setEmission(vec4(0.0, 0.0, 0.0, 1.0));
//	material.setShininess(0.0);*/
//	
//
//	
//	//light.setPosition(vec3(10, 0, 10));
//	light.apply();
//	//gluLookAt(10, 15, 17.5, 0, 0, 0, 0, 1, 0);
//	// ������� ��� ����������� �������
//	for (auto& go : graphicObjects) {
//		go.draw();
//		
//	}
//	// ����� ��������� � ������� �������
//	glutSwapBuffers();
//};
int count_color = 0;
// ������� ���������� ������ 20 ��



// ������� ��������� ������� ������

void keyboardFunc(unsigned char key, int x, int y)
{
	//printf("Key code is %i\n", key);
	// ��� �������� ������ ������ �������� ������ ������������
	switch (static_cast<char>(key)) {
	//case 'w':
	//	camera.rotateUpDown(5.0);
	//	break;
	//case 's':
	//	camera.rotateUpDown(-5.0);
	//	break;
	//case 'a':
	//	camera.rotateLeftRight(5.0);
	//	break;
	//case 'd':
	//	camera.rotateLeftRight(-5.0);
	//	break;
	//case '+':
	//	camera.zoomInOut(0.2);
	//	break;
	//case '-':
	//	camera.zoomInOut(-0.2);
	//	break;
	}
};


void main(int argc, char** argv)
{

	//setlocale(LC_ALL, "ru");

	//ofstream MyFile("11.txt");
	// ������������� ���������� GLUT
	glutInit(&argc, argv);
	// ������������� ������� (������ ������)
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	// �������� ����:
	// 1. ������������� ������� ����� ���� ����
	glutInitWindowPosition(200, 200);
	// 2. ������������� ������ ����
	glutInitWindowSize(800, 600);
	// 3. ������� ����
	glutCreateWindow("Laba 8");


	GLenum err = glewInit();
	if (GLEW_OK != err) {
		printf("Error: %s\n", glewGetErrorString(err));
	}
	printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	if (GLEW_ARB_vertex_buffer_object) {
		printf("VBO is supported\n");
	}


	initData();
	// ��������� ������� ��������� ������
	// ������������� �������, ������� ����� ���������� ��� ����������� ����
	glutDisplayFunc(display);
	// ������������� �������, ������� ����� ���������� ��� ��������� �������� ����
	glutReshapeFunc(reshape);
	// ������������� �������, ������� ����� ������� ����� 20 ��
	glutIdleFunc(simulation);

	// ������������� �������, ������� ����� ���������� ��� ������� �� �������
	glutKeyboardFunc(keyboardFunc);

	// �������� ���� ��������� ��������� ��
	glutMainLoop();
};