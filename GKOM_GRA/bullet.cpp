#include <math.h>
#include "bullet.hpp"
#include "GameState.hpp"

Bullet::Bullet(Vector3<float> pos) {
	position = pos;
	position.y -= 1;
	speed = 60;
}

void Bullet::Move() {	
	position.z += speed / 1000 * Game.DeltaTime();
}

void Bullet::Repaint() {
	glColor3f(2.0, 2.0, 2.0);
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glutSolidSphere(0.7, 10, 10);
	glPopMatrix();
}
