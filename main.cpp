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

// используем пространство имен стандартной библиотеки
using namespace glm;
using namespace std;

// функция, вызываемая при изменении размеров окна
void reshape(int w, int h)
{
	// установить новую область просмотра, равную всей области окна
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	// установить матрицу проекции с правильным аспектом
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (float)w / h, 0.2, 70.0);
};

// функция вызывается при перерисовке окна
// в том числе и принудительно, по командам glutPostRedisplay

//void display(void)
//{
//	
//	// отчищаем буфер цвета и буфер глубины
//	glClearColor(0.00, 0.00, 0.00, 1.0);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	// включаем тест глубины
//	glEnable(GL_DEPTH_TEST);
//	// устанавливаем камеру
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
//	// выводим все графические объекты
//	for (auto& go : graphicObjects) {
//		go.draw();
//		
//	}
//	// смена переднего и заднего буферов
//	glutSwapBuffers();
//};
int count_color = 0;
// функция вызывается каждые 20 мс



// Функция обработки нажатия клавиш

void keyboardFunc(unsigned char key, int x, int y)
{
	//printf("Key code is %i\n", key);
	// для провекри класса камеры вызываем методы передвижения
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
	// инициализация библиотеки GLUT
	glutInit(&argc, argv);
	// инициализация дисплея (формат вывода)
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	// СОЗДАНИЕ ОКНА:
	// 1. устанавливаем верхний левый угол окна
	glutInitWindowPosition(200, 200);
	// 2. устанавливаем размер окна
	glutInitWindowSize(800, 600);
	// 3. создаем окно
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
	// УСТАНОВКА ФУНКЦИЙ ОБРАТНОГО ВЫЗОВА
	// устанавливаем функцию, которая будет вызываться для перерисовки окна
	glutDisplayFunc(display);
	// устанавливаем функцию, которая будет вызываться при изменении размеров окна
	glutReshapeFunc(reshape);
	// устанавливаем функцию, которая будет вызвана через 20 мс
	glutIdleFunc(simulation);

	// устанавливаем функцию, которая будет вызываться при нажатии на клавишу
	glutKeyboardFunc(keyboardFunc);

	// основной цикл обработки сообщений ОС
	glutMainLoop();
};