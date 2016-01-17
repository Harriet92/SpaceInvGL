#pragma once

#include "world.hpp"
#include "alien.hpp"
#include "MathHelpers.hpp"

const float speed = 1.0f;

class Bullet {
public:
	Bullet(Vector3<float>);
	float X() const { return position.x; }
	float Y() const { return position.y; }
	float Z() const { return position.z; }
	void Move();
	void Repaint();
private:
	Vector3<float> position;
	float speed;
};
