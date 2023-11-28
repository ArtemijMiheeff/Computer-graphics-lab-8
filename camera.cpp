#include "camera.h"


// ��������� ������� ������
void Camera::setPosition(vec3 position)
{
	// ���������� ������ - ���������� �� ������ ������� ��������� �� �������� �������
	r = length(position);
	// ���������� ������������ ����:
	// ��� ���� ����� �������� �� ������ ��������� � ����������� (v1)
	// � ��������� ����� ������� �� �������������� ��������� (v2)
	// ��� ����������� ���� ������������ ��������� ������������ ��������������� �������� 
	vec3 v1 = position;
	vec3 v2 = vec3(v1.x, 0, v1.z);
	float cos_y = dot(normalize(v1), normalize(v2));
	angleY = degrees(acos(cos_y));
	// ����������� ������� ���������� �������������� ����:
	// ��� ���� ����� ��������� (v2) � ��������� �������� ����� ��� Ox
	float cos_x = dot(normalize(v2), vec3(1, 0, 0));
	angleX = degrees(acos(cos_x));
	// ������������� ������� (��� ������������� ������ ����������)
	recalculatePosition();
}
Camera::Camera()
{
	position = vec3(0, 0, 0);
	r = 1.0f;
	angleX = 0.0f;
	angleY = 0.0f;
}
Camera::Camera(vec3 position)
{
	setPosition(position);
}
Camera::Camera(float x, float y, float z)
{
	setPosition(vec3(x,y,z));
}
vec3 Camera::getPosition()
{
	return position;
}
void Camera::rotateLeftRight(float degree)
{
	angleX += degree;
	recalculatePosition();
}
void Camera::rotateUpDown(float degree)
{
	angleY += degree;
	std::cout << angleY << std::endl;
	if (angleY >= 80)
	{
		angleY = 80;
		std::cout << "test rotate";
	}
	if (angleY < 5)
	{
		angleY = 5;
		std::cout << "test rotate";
	}
	recalculatePosition();
}
void Camera::zoomInOut(float degree)
{
	r += degree;

	if (r > 52)
	{
		r = 52;
	}

	if (r < 2)
	{
		r = 2;
	}
	recalculatePosition();
}
void Camera::apply()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(position.x, position.y, position.z, 0, 0, 0, 0, 1, 0);
}
void Camera::recalculatePosition()
{

	float angle_x = radians(angleX);
	float angle_y = radians(angleY);

	position.x = r * sin(angle_y) * cos(angle_x);
	position.y = r * cos(angle_y);
	position.z = r * sin(angle_y) * sin(angle_x);
}