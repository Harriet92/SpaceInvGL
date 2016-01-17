#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "world.hpp"
#include "texLoader.hpp"
#include "Camera.hpp"
#include "Input.hpp"
#include "GameState.hpp"
#include "GuiRenderer.hpp"

World w;
GLfloat ambientLight [] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat diffuseLight [] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat specularLight [] = { 0.1f, 0.1f, 0.1f, 1.0f };

void renderScene() {
	Game.GameLoop();
	w.DrawEnvironment();
	glutSwapBuffers();
}

int main(int argc, char* argv []) {
	srand(time(0));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutCreateWindow("Space Invaders");
	Camera::Init();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	if (!w.initTexture()) {
		exit(1);
	}
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	GLfloat lightpos [] = { 1, 4,5, 0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	glEnable(GL_LIGHT0);
	glLightModeli(GL_LIGHT_MODEL_AMBIENT, GL_TRUE);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	GLfloat mat_shininess [] = { 50.0};
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glEnable(GL_COLOR_MATERIAL);
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(&Camera::ChangeSize);
	glutKeyboardFunc(&Input::ProcessNormalKeys);
	glutKeyboardUpFunc(&Input::ReleaseNormalKey);
	glutSpecialFunc(&Input::PressKey);
	glutSpecialUpFunc(&Input::ReleaseKey);
	glutMotionFunc(&Input::MouseMove);
	glutEntryFunc(&Input::MouseEnter);
	glutMouseFunc(&Input::MouseClick);
	glutMainLoop();
	return(0);
}
