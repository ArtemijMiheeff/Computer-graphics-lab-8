#include "GameObject.h"

GameObject::GameObject()
{
	position = ivec2(0.0, 0.0);
	graphicObject = GraphicObject();
	sost = MoveDirection::STOP;
}
void GameObject::setGraphicObject(const GraphicObject& graphicObject)
{
	this->graphicObject = graphicObject;
};
// установка логических координат (два перегруженных метода для удобства)
void GameObject::setPosition(int x, int y) {
	position.x = x;
	position.y = y;
	graphicObject.setPosition(vec3(x - 10, 0.5, y - 10));
}
void GameObject::setPosition(ivec2 position) {
	this->position = position;
	graphicObject.setPosition(vec3(position.x - 10, 0.5, position.y - 10));
}
// получение текущих логических координат
ivec2 GameObject::getPosition()
{
	return position;
};
void GameObject::move(MoveDirection direction, float speed) {
	if (this->sost == MoveDirection::STOP) {
		this->sost = direction;
		this->speed = speed;
		this->progress = 0.0;
		switch (direction)
		{
		case MoveDirection::STOP: {
			break;
		}
		case MoveDirection::LEFT: {
			position.x -= 1;
			break;
		}
		case MoveDirection::RIGHT: {
			position.x += 1;
			break;
		}
		case MoveDirection::UP: {
			position.y -= 1;
			break;
		}
		case MoveDirection::DOWN: {
			position.y += 1;
			break;
		}
		}
	}
}
bool GameObject::isMoving() {
	if (sost == MoveDirection::STOP) return false;
	else return true;
}
void GameObject::simulate(float sec) {
	float distance = this->speed * sec;
	progress += distance;
	vec3 currentPos = graphicObject.getPosition();
	if (progress < 1) {
		switch (this->sost)
		{
		case MoveDirection::STOP: {
			break;
		}
		case MoveDirection::LEFT: {
			currentPos.x -= distance;
			break;
		}
		case MoveDirection::RIGHT: {
			currentPos.x += distance;
			break;
		}
		case MoveDirection::UP: {
			currentPos.z -= distance;
			break;
		}
		case MoveDirection::DOWN: {
			currentPos.z += distance;
			break;
		}
		}
	}
	else {
		progress = 1.0;
		sost = MoveDirection::STOP;
		currentPos = vec3(this->position.x - 10, 0.5, this->position.y - 10);
	}
	graphicObject.setPosition(currentPos);
}
// вывод игрового объекта на экран
void GameObject::draw(void)
{
	graphicObject.draw();
};