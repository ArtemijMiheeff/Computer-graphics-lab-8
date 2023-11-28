#include "Simulation.h"
#include "Data.h"

#define SPEED 5.0f
#define SPEED_WITH_BOX 3.0f
float simulationTime = 0.0;
unsigned int lastClock = clock();

//int counter = 1;
//int counter1 = 0;
//
//float r = 1;
//float g = 0.5;
//float b = 0.5;


//vector<vec3> color{ vec3(0.0, 0.0, 0.0), vec3(0.0, 0.0, 1.0), vec3(1.0, 0.0, 0.0), vec3(1.0, 1.0, 0.0), vec3(0.5, 0.0, 1.0) };



void movePlayer() {
	ivec2 pos = player->getPosition();
	if (GetAsyncKeyState(0x57) && (!player->isMoving())) {	//key W
		if (passabilityMap[pos.x][pos.y - 1] == 0) {
			player->move(MoveDirection::UP, SPEED);
		}
		if ((passabilityMap[pos.x][pos.y - 1] == 1)
			&& (passabilityMap[pos.x][pos.y - 2]) == 0) {
			passabilityMap[pos.x][pos.y - 2] = 1;
			passabilityMap[pos.x][pos.y - 1] = 0;
			map_object[pos.x][pos.y - 1]->move(MoveDirection::UP, SPEED_WITH_BOX);
			map_object[pos.x][pos.y - 2] = map_object[pos.x][pos.y - 1];
			map_object[pos.x][pos.y - 1] = nullptr;
			player->move(MoveDirection::UP, SPEED_WITH_BOX);
		}
		//cout << "W" << endl;
	}
	if (GetAsyncKeyState(0x53) && (!player->isMoving())) {	//key S
		if (passabilityMap[pos.x][pos.y + 1] == 0) {
			player->move(MoveDirection::DOWN, SPEED);
		}
		if ((passabilityMap[pos.x][pos.y + 1] == 1)
			&& (passabilityMap[pos.x][pos.y + 2]) == 0) {
			passabilityMap[pos.x][pos.y + 2] = 1;
			passabilityMap[pos.x][pos.y + 1] = 0;
			map_object[pos.x][pos.y + 1]->move(MoveDirection::DOWN, SPEED_WITH_BOX);
			map_object[pos.x][pos.y + 2] = map_object[pos.x][pos.y + 1];
			map_object[pos.x][pos.y + 1] = nullptr;
			player->move(MoveDirection::DOWN, SPEED_WITH_BOX);
		}
		//cout << "S" << endl;
	}
	if (GetAsyncKeyState(0x41) && (!player->isMoving())) {	//key A
		if (passabilityMap[pos.x - 1][pos.y] == 0) {
			player->move(MoveDirection::LEFT, SPEED);
		}
		if ((passabilityMap[pos.x - 1][pos.y] == 1)
			&& (passabilityMap[pos.x - 2][pos.y]) == 0) {
			passabilityMap[pos.x - 2][pos.y] = 1;
			passabilityMap[pos.x - 1][pos.y] = 0;
			map_object[pos.x - 1][pos.y]->move(MoveDirection::LEFT, SPEED_WITH_BOX);
			map_object[pos.x - 2][pos.y] = map_object[pos.x - 1][pos.y];
			map_object[pos.x - 1][pos.y] = nullptr;
			player->move(MoveDirection::LEFT, SPEED_WITH_BOX);
		}
	}
	if (GetAsyncKeyState(0x44) && (!player->isMoving())) {	//key D
		if (passabilityMap[pos.x + 1][pos.y] == 0) {
			player->move(MoveDirection::RIGHT, SPEED);
		}
		if ((passabilityMap[pos.x + 1][pos.y] == 1)
			&& (passabilityMap[pos.x + 2][pos.y]) == 0) {
			passabilityMap[pos.x + 2][pos.y] = 1;
			passabilityMap[pos.x + 1][pos.y] = 0;
			map_object[pos.x + 1][pos.y]->move(MoveDirection::RIGHT, SPEED_WITH_BOX);
			map_object[pos.x + 2][pos.y] = map_object[pos.x + 1][pos.y];
			map_object[pos.x + 1][pos.y] = nullptr;
			player->move(MoveDirection::RIGHT, SPEED_WITH_BOX);
		}
	}
	player->simulate(simulationTime);
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			if (map_object[i][j] != nullptr) map_object[i][j]->simulate(simulationTime);
		}
	}
}

void simulation()
{
	// устанавливаем признак того, что окно нуждается в перерисовке
	glutPostRedisplay();

	glutMouseFunc(mouseWheel);

	if (GetAsyncKeyState(VK_RBUTTON))
	{
		//std::cout << "LSHIFT\n";
		if (GetCursorPos(&MouseXY)) {
			//std::cout << MouseXY.x << "," << MouseXY.y << "\n";
			camera.rotateUpDown((240 - MouseXY.y) / 2);
			camera.rotateLeftRight((320 - MouseXY.x) / 2);
			SetCursorPos(320, 240);
		}
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		camera.rotateLeftRight(-0.1);
	};
	if (GetAsyncKeyState(VK_RIGHT))
	{
		camera.rotateLeftRight(0.1);
	};
	if (GetAsyncKeyState(VK_UP))
	{
		camera.rotateUpDown(0.1);
	};
	if (GetAsyncKeyState(VK_DOWN))
	{
		camera.rotateUpDown(-0.1);
	};
	if (GetAsyncKeyState(VK_SPACE))
	{
		camera.zoomInOut(0.1);
	};
	if (GetAsyncKeyState(VK_SHIFT))
	{
		camera.zoomInOut(-0.1);
	};

	simulationTime = float(clock() - lastClock) / CLOCKS_PER_SEC;
	lastClock = clock();

	movePlayer();

	/*counter1++;
	if (counter1 == 50) {
		switch (counter)
		{
		case 1:
			r = color[0][0];
			g = color[0][1];
			b = color[0][2];
			counter++;
			counter1 = 0;
			break;
		case 2:
			r = color[1][0];
			g = color[1][1];
			b = color[1][2];
			counter++;
			counter1 = 0;
			break;
		case 3:
			r = color[2][0];
			g = color[2][1];
			b = color[2][2];
			counter = 1;
			counter1 = 0;
			break;
		}
	}*/
	//counter1 = 0;
	// устанавливаем признак того, что окно нуждается в перерисовке
	glutPostRedisplay();
	// эта же функция будет вызвана еще раз через 20 мс
	//glutTimerFunc(20, simulation, 0);
};

void mouseWheel(int button, int dir, int x, int y) {
	if (button == 4) {
		camera.zoomInOut(0.5);
	}
	else if (button == 3) {
		camera.zoomInOut(-0.5);
	}
}