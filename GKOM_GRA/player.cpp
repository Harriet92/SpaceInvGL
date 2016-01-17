#include <stdlib.h>
#include "player.hpp"
#include "glut.h"
#include "GameState.hpp"

Player::Player() : texture() {
	position.z = 10;
	moveSpeed = 30;
}

void Player::Move(int direction) {
	float newX = position.x + direction * moveSpeed / 1000 * Game.DeltaTime();
	if (newX > WORLDSIZE - 2) { newX = WORLDSIZE - 2; }
	if (newX < 0) { newX = 0; }
	position.x = newX;
}

void Player::Shoot() {
	Bullet *b = new Bullet(position);
	Game.bullets.push_back(b);
}

void Player::Draw() {
	float pheight = 10;
	float pwidth = 10;

	glColor3ub(255, 20, 196);

	glPushMatrix();
	glScalef(2.f, 0.2f, 2.f);
	glutSolidCone(1, pwidth / 2, 10, 10);
	glPopMatrix();

	glColor3ub(0, 155, 210);

	glPushMatrix();
	glScalef(pwidth / 2, 0.2f, 0.5f);
	glutSolidCube(pwidth / 5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-pwidth / 2, 0.0f, 0.0f);
	glScalef(pwidth / 5, 0.2f, 2 * pwidth / 5);
	glutSolidOctahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(pwidth / 2, 0.0f, 0.0f);
	glScalef(pwidth / 5, 0.2f, 2 * pwidth / 5);
	glutSolidOctahedron();
	glPopMatrix();

	glColor3ub(255, 131, 5);

	glPushMatrix();
	glTranslatef(0, 0.0f, -pwidth / 10);
	glutSolidSphere(pwidth / 8, 10, 10);
	glPopMatrix();
	return;
}

