#include "Data.h"


// используем пространство имен стандартной библиотеки
using namespace glm;
using namespace std;

Camera camera(vec3(0, 25, 40));

Light light(vec3(0, 5, 0));

// список графических объектов
vector <GraphicObject> graphicObjects;
vector <shared_ptr<Mesh>> meshes;

// используемые материалы
std::vector<std::shared_ptr<PhongMaterial>> materials;

// карта проходимости
int passabilityMap[21][21] = {
 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
 3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,4,3,
 3,0,2,1,2,0,2,0,2,2,2,1,2,0,2,0,2,0,2,2,3,
 3,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,1,0,0,0,3,
 3,0,1,0,2,2,1,2,2,0,2,0,2,2,2,1,2,0,2,0,3,
 3,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,2,0,3,
 3,0,2,2,1,1,2,0,2,0,2,2,2,2,2,0,2,2,2,0,3,
 3,0,2,0,0,0,2,0,2,0,0,0,0,0,2,0,0,0,0,0,3,
 3,0,2,0,2,2,2,0,2,0,2,2,1,2,2,2,1,2,2,0,3,
 3,0,0,0,2,0,0,0,2,0,2,0,0,0,0,0,0,0,1,0,3,
 3,2,2,2,2,0,2,2,2,0,2,0,2,2,2,2,2,2,2,0,3,
 3,0,0,0,2,0,0,0,1,0,2,0,0,0,2,0,0,0,0,0,3,
 3,0,2,0,2,2,2,0,2,1,2,0,2,2,2,0,2,2,2,2,3,
 3,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,2,0,0,0,3,
 3,2,2,2,2,0,2,2,2,0,2,2,2,0,1,0,2,2,2,0,3,
 3,0,0,0,0,0,2,0,2,0,0,0,2,0,1,0,0,0,2,0,3,
 3,0,2,0,2,1,2,0,2,0,2,2,2,0,2,2,2,0,2,0,3,
 3,0,1,0,1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,3,
 3,0,2,1,2,0,2,2,2,2,2,0,2,0,2,0,2,2,2,2,3,
 3,0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,0,3,
 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
};

//Mesh mesh_object;
//std::shared_ptr<Mesh> mesh_object;
std::shared_ptr<GameObject> map_object[21][21];

//GraphicObject plane;
//GraphicObject Box;
//GraphicObject ChamferBox;
//GraphicObject BorderBox;
//GraphicObject Sphere;


shared_ptr<GameObject> player;
GraphicObject planeGraphicObject;
GameObjectFactory gameObjectFactory;
POINT MouseXY;


// функция для инициализации всех общих данных(камера, объекты и т.д.)
void initData()
{

	light.setAmbient(vec4(1, 1, 1, 1));
	light.setDiffuse(vec4(1, 1, 1, 1));
	light.setSpecular(vec4(0.1, 0.1, 0.1, 1));

	// инициализация фабрики (в дальнейшем на основе json-файла)
	gameObjectFactory.init("data/GameObjectsDescription.json");
	// инициализация объектов сцены
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			switch (passabilityMap[i][j]) {
			case 1:
				map_object[i][j] = gameObjectFactory.create(GameObjectType::LIGHT_OBJECT, i, j);
				break;
			case 2:
				map_object[i][j] = gameObjectFactory.create(GameObjectType::HEAVY_OBJECT, i, j);
				break;
			case 3:
				map_object[i][j] = gameObjectFactory.create(GameObjectType::BORDER_OBJECT, i, j);
				break;
			default:
				map_object[i][j] = nullptr;
				break;
			}
		}
	}
	// инициализация главного героя
	player = gameObjectFactory.create(GameObjectType::PLAYER, 19, 1);
	// инициализация плоскости
	planeGraphicObject.setPosition(vec3(0, 0, 0));
	shared_ptr<Mesh> planeMesh = make_shared<Mesh>();
	planeMesh->load("data\\meshes\\HighPolyPlane.obj");
	planeGraphicObject.setMesh(planeMesh);
	shared_ptr<PhongMaterial> planeMaterial = make_shared<PhongMaterial>();
	planeMaterial->load("data\\materials\\PlaneMaterial.txt");
	planeGraphicObject.setMaterial(planeMaterial);
	cout << "All is normal map" << endl;
};