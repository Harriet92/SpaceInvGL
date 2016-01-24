#pragma once

#include "GL/glut.h"
#include "texloader.hpp"

class Alien {
public:
	Alien(float, int, float);
	float X() const { return x; }
	float Z() const { return z; }
	static float Height() { return height; }
	static float Width() { return width; }
	double IsAlive() { return alive; }
	static void SetSpeedModifier(float newVal) { speedModifier = newVal; }
	void drawAlien();
	void move();
	void Die();
private:
	float x;
	float z;
	int rowNumber;
	float offset;
	float currDx;
	static float height;
	static float width;
	static float speed;
	static float speedModifier;
	int distance;
	int hp;
	bool alive;
	int direction;
	TexLoader texture;
};
