#include "Camera.h"
#include "GL/glut.h"

Camera::Camera() : cameraType(0)
{
	position.x = 0;
	position.y = 10;
	position.z = 1;
}

void Camera::Draw()
{
	switch (cameraType)
	{
	case 0:
		gluLookAt(position.x, position.y, position.z, position.x, position.y - 10, position.z - 1, 0.0, 1.0, 0.0);
		break;
	case 1:
		gluLookAt(0.0, 1.0, position.z, 0.0, 1.0, -9.0, 0.0, 1.0, 0.0);
		break;
	case 2:
		gluLookAt(0.0, 1.0, 10, 0.0, 1.0, 9.0, 0.0, 1.0, 0.0);
		break;
	case 3:
		gluLookAt(15.0+position.x, 3.0, 0.0, 0.0, 5.0, 0.0, 0.0, 1.0, 0.0);
		break;
	default:
		break;
	}
}

void Camera::MovePosition(float x, float y, float z)
{
	position.x += x;
	position.y += y;
	position.z += z;
}

void Camera::SetPosition(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

void Camera::ChangeCamera(int num)
{
	cameraType = num;
}