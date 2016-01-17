#include "GuiRenderer.hpp"
#include "glut.h"
#include "Camera.hpp"
#include "world.hpp"

void GuiRenderer::RenderString(const int xpos, const int ypos, char * str) {
	char *c;
	glPushMatrix();
	glColor3ub(40, 255, 40);
	glTranslatef(xpos * (WORLDSIZE + 10) / 2 , 0, (WORLDSIZE + 10) / 2 * ypos);
	glRasterPos3f(0, 0, 0);
	glPopMatrix();
	for (c = str; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}

void GuiRenderer::RenderBigRedString(const int xpos, const int ypos, char * str) {
	char *c;
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(xpos * WORLDSIZE / 2 + strlen(str), 0, WORLDSIZE / 2 * ypos);
	glRasterPos3f(0, 0, 0);
	glPopMatrix();
	for (c = str; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}