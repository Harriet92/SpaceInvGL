#include "GameState.hpp"
#include "AlienManager.hpp"
#include "GL/glut.h"
#include "Camera.hpp"
#include "Input.hpp"
#include "GuiRenderer.hpp"

GameState Game;

const int POINTS_FOR_KILL = 1;
GameState::GameState() {
	timeSinceLastCheck = 0;
	level = 1;
}

void GameState::GameLoop() {
	calculateDeltaTime();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (!gameOver) {
		checkLevel();
		moveBullets();
		alienManager.MoveAll();
		movePlayer();
	}
	guiUpdate();
	Camera::LookAtUpdate();
}

void GameState::calculateDeltaTime() {
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = currentTime - timeSinceLastCheck;
	timeSinceLastCheck = currentTime;
}

void GameState::checkLevel() {
	if (timeSinceLastCheck >= 1000 * 5 * level) {
		level++;
		alienManager.SpawnRow(level - 1);
	}
}

void GameState::movePlayer() {
	glPushMatrix();
	if (Input::GetMove()) {
		player.Move(Input::GetMove());
	}
	if (Input::shoot) {
		Input::shoot = false;
		player.Shoot();
	}
	glTranslatef(player.X(), 0, player.Z());
	player.Draw();
	glPopMatrix();
}

void GameState::moveBullets() {
	for (int i = bullets.size() - 1; i >=0 ; i--) {
		Bullet *b = bullets[i];
		bool destroy = b->Z() > WORLDSIZE;
		if (!destroy && alienManager.CheckCollision(*b)) {
			destroy = true;
			score += POINTS_FOR_KILL;
		}
		if(destroy) {
			bullets[i] = bullets[bullets.size() - 1];
			delete b;
			bullets.pop_back();
		}
		else {
			b->Move();
			b->Repaint();
		}
	}
}

void GameState::guiUpdate() {
	char lvlstr[10];
	sprintf_s(lvlstr, 10, "Level: %d", level);
	GuiRenderer::RenderString(GuiRenderer::LEFT, GuiRenderer::BOTTOM, lvlstr);
	char scorestr[10];
	sprintf_s(scorestr, 10, "Score: %d", score);
	GuiRenderer::RenderString(GuiRenderer::RIGHT, GuiRenderer::BOTTOM, scorestr);
	if (gameOver) {
		char gostr[27];
		sprintf_s(gostr, 27, "GAME OVER! Your score: %d", score);
		GuiRenderer::RenderBigRedString(GuiRenderer::MIDDLE, GuiRenderer::MIDDLE, gostr);
	}
}


