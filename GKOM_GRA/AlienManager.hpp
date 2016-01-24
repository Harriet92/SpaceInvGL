#pragma once
#include <list>
#include "GL/glut.h"
#include "alien.hpp"
#include "bullet.hpp"

class AlienManager {
public:
	AlienManager();
	void SpawnRow(int);
	void MoveAll();
	bool CheckCollision(Bullet);
	bool AliensOnTheLine();
private:
	int aliensInRow;
	float offset;
	GLint alienDL;
	std::list<Alien*> aliens;
};
