#pragma once
#include "GL/glut.h"
#include "player.hpp"
#include "MathHelpers.hpp"

class Camera {
public:
	static void Init();
	static float X() { return eyePosition.x; }
	static float Y() { return eyePosition.y; }
	static float Z() { return eyePosition.z; }
	static void ChangeSize(int w, int h);
	static void OrientMe(float verticalAngle);
	static GLfloat* EyePosition() {
		GLfloat pos [] = { eyePosition.x, eyePosition.y, eyePosition.z };
		return pos;
	}
	static void LookAtUpdate();
	static float UpVector[3];
	static Vector3<float> ViewDirection;
	static GLfloat* Direction() {
		GLfloat direction [] = { ViewDirection.x, ViewDirection.y, ViewDirection.z };
		return direction;
	}
private:
	static Vector3<float> eyePosition;
};
