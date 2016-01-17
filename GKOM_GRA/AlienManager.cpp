#include "world.hpp"
#include "AlienManager.hpp"

using namespace std;

const float ALIENS_SPACE = Alien::Width();

inline float mod(float f) {
	return f >= 0 ? f : -f;
}

AlienManager::AlienManager() {
	offset = WORLDSIZE / 5;
	aliensInRow = (WORLDSIZE - offset) / (Alien::Width() + ALIENS_SPACE);
	SpawnRow(0);
}

void AlienManager::SpawnRow(int rowNo) {
	for (int i = 0; i < aliensInRow; i++)
	{
		Alien *newAlien = new Alien(WORLDSIZE - 2 - i * (Alien::Width() + ALIENS_SPACE), rowNo, offset);
		aliens.push_back(newAlien);
	}
}

void AlienManager::MoveAll() {
	std::list<Alien*>::iterator it;
	for (it = aliens.begin(); it != aliens.end(); ++it) {
		if ((*it)->IsAlive()) {
			glPushMatrix();
			glTranslatef((*it)->X(), 0, (*it)->Z());
			(*it)->move();
			(*it)->drawAlien();
			glPopMatrix();
		}
	}
}


bool AlienManager::CheckCollision(Bullet bullet) {
	std::list<Alien*>::iterator it;
	for (it = aliens.begin(); it != aliens.end(); ++it) {
		if ((*it)->IsAlive() &&
			(*it)->Z() > bullet.Z() && (*it)->Z() - (*it)->Height() < bullet.Z() &&
			(*it)->X() > bullet.X() && (*it)->X() - (*it)->Width() < bullet.X())
		{
			(*it)->Die();
			return true;
		}
	}
	return false;
}

