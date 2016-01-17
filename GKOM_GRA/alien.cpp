#include <stdlib.h>
#include <math.h>
#include "world.hpp"
#include "alien.hpp"
#include "GameState.hpp"

float Alien::speedModifier = 1;
float Alien::speed = 10;
float Alien::height = 5;
float Alien::width = 5;
Alien::Alien(float sx, int row, float soffset) : texture() {
	x = sx;
	rowNumber = row;
	offset = soffset;
	currDx = 0;
	z = WORLDSIZE - height;
	direction = -1;
	alive = true;
	hp = 5;
}

void Alien::drawAlien() {
	glColor3f(1.0f, 0.0f, 0.0f);

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.75f);
	glScalef(1.f, 0.2f, 0.5f);
	glutSolidCube(height);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5f, 0.0f, -0.75f);
	glScalef(0.25f, 0.2f, 0.5f);
	glutSolidCube(height);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5f, 0.0f, -0.75f);
	glScalef(0.25f, 0.2f, 0.5f);
	glutSolidCube(height);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.f, 0.0f, -1.f);
	glScalef(0.7f, 0.2f, 0.7f);
	glutSolidIcosahedron();
	glPopMatrix();
	return;
}


void Alien::Die() {
	alive = false;
}

void Alien::move() {
	if (!alive) return;
	float dx = sqrt(Game.Level()) * speed / 1000 * Game.DeltaTime();
	float newX = x + direction *  dx;
	if (currDx >= offset) {
		direction *= -1;
		currDx = 0;
	}
	currDx += dx;
	x += direction * dx;
	z = WORLDSIZE - (Game.Level() - rowNumber) * (height + 2);
	if (z <= Game.DeadLine) {
		Game.GameOver();
	}
}
