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

#include "rapidjson/document.h"
#include "GameObject.h"

using namespace std;
using namespace rapidjson;
using namespace glm;

// ����������� ����� ������� �������� 
enum class GameObjectType {
	LIGHT_OBJECT, // ������ ������� ������
	HEAVY_OBJECT, // ������� ������� ������
	BORDER_OBJECT, // ��������� ������� ������
	PLAYER, // ������� ������ ��� ������������� ������
	BOMB, // ������� ������ ��� ������������� �����
	MONSTER // ������� ������ ��� ������������� ��������
};


// ����� ��� �������� ������� ��������
class GameObjectFactory
{
public:
	// ������������� �������:
	// �������� ����� � ��������� ���������� ���������
	bool init(std::string filename);
	// �������� ������ ������� ��������� ����
	std::shared_ptr<GameObject> create(GameObjectType type, int x, int y);
private:
	// ���� ��� ������� ���� �������
	std::vector<std::shared_ptr<Mesh>> meshes;
	// ��������� ��� ������� ���� �������
	std::vector<std::shared_ptr<PhongMaterial>> materials;
};


