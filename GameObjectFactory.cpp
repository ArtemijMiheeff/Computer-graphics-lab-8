#include "GameObjectFactory.h"

// инициализация фабрики (загрузка мешей и установка параметров материала)
bool GameObjectFactory::init(string filename) {
	fstream File(filename);
	if (!File) {
		cout << "JSON file error\n";
		return false;
	}
	else {
		cout << "JSON file open\n";
	}
	string line;
	getline(File, line, static_cast<char>(0));
	File.close();
	//cout << line << endl;
	// парсим - если ошибка, то выходим
	Document document;
	document.Parse(line.c_str());
	if (document.GetParseError() != 0) {
		cout << "неверный формат файла\n";
		return false;
	}
	else
	{
		cout << "All is ok" << endl;
	}
	string objectsType[] = { "LightObject", "HeavyObject",
	"BorderObject", "Player", "Bomb", "Monster" };
	for (auto& m : document.GetObject()) {
		string MeshFileName = document[m.name.GetString()]["mesh"].GetString();
		meshes.push_back(make_shared<Mesh>());
		meshes[meshes.size() - 1]->load(MeshFileName);

		const Value& material = document[m.name.GetString()]["material"];
		vec4 dif, amb, spec, emis;
		float shin = material["shininess"].GetFloat();
		for (int i = 0; i < 4; i++) {
			dif[i] = material["diffuse"][i].GetFloat();
			//cout << dif[i] << endl;
			amb[i] = material["ambient"][i].GetFloat();
			//cout << amb[i] << endl;
			spec[i] = material["specular"][i].GetFloat();
			//cout << spec[i] << endl;
			emis[i] = material["emission"][i].GetFloat();
			//cout << emis[i] << endl;
		}
		materials.push_back(make_shared<PhongMaterial>());
		//materials.push_back(nullptr);
		materials[materials.size() - 1]->setAmbient(amb);
		materials[materials.size() - 1]->setDiffuse(dif);
		materials[materials.size() - 1]->setEmission(emis);
		materials[materials.size() - 1]->setShininess(shin);
		materials[materials.size() - 1]->setSpecular(spec);
		//cout << "LRALFDALYAFH" << endl;
	}
}
// создание нового объекта заданного типа
std::shared_ptr<GameObject> GameObjectFactory::create(GameObjectType type, int x, int y) {
	shared_ptr <GameObject>GameObjPtr = make_shared<GameObject>();
	const int correct = -10;
	switch (type) {
	case GameObjectType::LIGHT_OBJECT: {
		GraphicObject obj;
		obj.setMaterial(materials[0]);
		obj.setMesh(meshes[0]);
		GameObjPtr->setGraphicObject(obj);
		GameObjPtr->setPosition(x, y);
		break;
	}
	case GameObjectType::HEAVY_OBJECT: {
		GraphicObject obj;
		obj.setMaterial(materials[1]);
		obj.setMesh(meshes[2]);
		GameObjPtr->setGraphicObject(obj);
		GameObjPtr->setPosition(x, y);
		break;
	}
	case GameObjectType::BORDER_OBJECT: {
		GraphicObject obj;
		obj.setMaterial(materials[2]);
		obj.setMesh(meshes[2]);
		GameObjPtr->setGraphicObject(obj);
		GameObjPtr->setPosition(x, y);
		break;
	}
	case GameObjectType::PLAYER: {
		GraphicObject obj;
		obj.setMaterial(materials[3]);
		obj.setMesh(meshes[3]);
		GameObjPtr->setGraphicObject(obj);
		GameObjPtr->setPosition(x, y);
		break;
	}
	case GameObjectType::BOMB: {
		GraphicObject obj;
		obj.setMaterial(materials[4]);
		obj.setMesh(meshes[4]);
		GameObjPtr->setGraphicObject(obj);
		GameObjPtr->setPosition(x, y);
		break;
	}
	case GameObjectType::MONSTER: {
		GraphicObject obj;
		obj.setMaterial(materials[5]);
		obj.setMesh(meshes[5]);
		GameObjPtr->setGraphicObject(obj);
		GameObjPtr->setPosition(x, y);
		break;
	}
	default:
		break;
	}
	return GameObjPtr;
}