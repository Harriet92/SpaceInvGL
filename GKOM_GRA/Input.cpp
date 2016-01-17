#include "Input.hpp"
#include "glut.h"
#include "Camera.hpp"

int Input::move = 0;
float Input::strife;
float Input::angleUp;
float Input::mouseX;
float Input::mouseY;
bool Input::shoot = false;
bool Input::left_down;
void Input::ProcessNormalKeys(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);
	}
	if (key == 'a') {
		move = 1;
		return;
	}
	if (key == 'd') {
		move = -1;
		return;
	}
	if (key == 'w') {
		strife = -1.0f;
		return;
	}
	if (key == 's') {
		strife = 1.0f;
		return;
	}
}

void Input::ReleaseNormalKey(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);
	}
	if (key == 'a' || key == 'd') {
		move = 0;
	}
	if (key == 'w' || key == 's') {
		strife = 0.0f;
		return;
	}
}

void Input::PressKey(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		move = 1;
		break;
	case GLUT_KEY_RIGHT:
		move = -1;
		break;
	case GLUT_KEY_UP:
		if (GLUT_ACTIVE_CTRL) {
			move = 1.0f;
		}
		else {
			move = 1.0f;
		}
		break;
	case GLUT_KEY_DOWN:
		if (GLUT_ACTIVE_CTRL) {
			move = -1.0f;
		}
		else {
			move = -1.0f;
		}
		break;
	}
}

void Input::ReleaseKey(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
	case GLUT_KEY_RIGHT:
		move = 0;
		break;
	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN:
		strife = 0.0f;
	}
}

void Input::MouseMove(int mX, int mY) {
	if (!left_down) return;
	if (mouseY == -1) {
		mouseY = mY;
	}
	float dy = mY - mouseY;
	angleUp += dy / 200;
	mouseY = mY;
	Camera::OrientMe(angleUp);
}

void Input::MouseEnter(int state) {
	if (state == GLUT_LEFT) {
		mouseX = mouseY = -1;
	}
}

void Input::MouseClick(int button, int state, int x, int y) {
	shoot = button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN;
	left_down = button == GLUT_LEFT_BUTTON && state == GLUT_DOWN;
}