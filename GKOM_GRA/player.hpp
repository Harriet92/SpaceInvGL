#pragma once

#include <vector>
#include "bullet.hpp"
#include "MathHelpers.hpp"
#include "texloader.hpp"

class Player {
public:
	Player();
	void Move(int);
	void Shoot();
	void Draw();
	float X() const { return position.x; }
	float Y() const { return position.y; }
	float Z() const { return position.z; }
private:
	float moveSpeed;
	Vector3<float> position;
	TexLoader texture;
};
