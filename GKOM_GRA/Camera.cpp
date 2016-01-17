#include <stdlib.h>
#include <math.h>
#include "texloader.hpp"
#include "world.hpp"
#include "Camera.hpp"

GLfloat direction [];
float Camera::UpVector[3] = { 0.0f, 0.5f, 0.5f };
Vector3<float> Camera::ViewDirection;
Vector3<float> Camera::eyePosition;

const float startViewDir[3] = { 0., -1., 0. };

void Camera::Init() {
	ViewDirection = { startViewDir[0], startViewDir[1], startViewDir[2] };
	eyePosition.y = WORLDSIZE / 2 + 75;
	eyePosition.x = WORLDSIZE / 2 - 1;
	eyePosition.z = WORLDSIZE / 2 - 1;
	LookAtUpdate();
}


void Camera::ChangeSize(int w, int h) {
	if (h == 0) {
		h = 1;
	}
	float ratio = 1.0f * w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	LookAtUpdate();
}

void Camera::OrientMe(float verticalAngle) {
	ViewDirection.y = -sin(verticalAngle);
	ViewDirection.z = -cos(verticalAngle);
	LookAtUpdate();
}

void Camera::LookAtUpdate() {
	glLoadIdentity();
	gluLookAt(eyePosition.x, eyePosition.y,eyePosition.z,
		eyePosition.x, eyePosition.y + ViewDirection.y, eyePosition.z + ViewDirection.z,
		UpVector[0], UpVector[1],UpVector[2]);
}