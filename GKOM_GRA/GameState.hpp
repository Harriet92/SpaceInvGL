#pragma once
#include "AlienManager.hpp"
#include "player.hpp"

class GameState {
public:
	GameState();
	int DeltaTime() { return deltaTime; }
	int Level() { return level; }
	void GameLoop();
	void GameOver() { gameOver = true; };
	std::vector<Bullet*> bullets;
	const float DeadLine = 20;
private:
	AlienManager alienManager;
	Player player;
	int timeSinceLastCheck;
	int deltaTime;
	int level;
	int score;
	void moveBullets();
	void calculateDeltaTime();
	void checkLevel();
	void movePlayer();
	void guiUpdate();
	bool gameOver;
};

extern GameState Game;