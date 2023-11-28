#include "Display.h"
#include "Data.h"

void display(void)
{
	// �������� ����� ����� � ����� �������
	glClearColor(0.00, 0.00, 0.00, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// �������� ���� �������
	glEnable(GL_DEPTH_TEST);
	// ������������� ������
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera.apply();

	light.apply(GL_LIGHT0);
	//gluLookAt(10, 15, 17.5, 0, 0, 0, 0, 1, 0);
	// ������� ��� ����������� �������

	planeGraphicObject.draw();
	player->draw();
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (map_object[i][j] != nullptr)
			{
				map_object[i][j]->draw();
			}
		}
	}

	// ����� ��������� � ������� �������
	glutSwapBuffers();
};