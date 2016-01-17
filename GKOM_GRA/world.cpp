#include "world.hpp"
#include "glut.h"


World::World() {
	
}

bool World::initTexture() {
	char* textures [] = { "space.bmp"};
	GLuint textureIds[4];
	glGenTextures(4, textureIds);
	for (int i = 0; i < TEXTURES; ++i) {
		if (!Textures[i].load(textures[i])) {
			return false;
		}
		Textures[i].ID = textureIds[i];
		glBindTexture(GL_TEXTURE_2D, Textures[i].ID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB,
			Textures[i].getImageWidth(),
			Textures[i].getImageHeight(),
			GL_RGB, GL_UNSIGNED_BYTE,
			Textures[i].image);
	}
	return true;
}

void World::DrawEnvironment() {
	glEnable(GL_TEXTURE_2D);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, Textures[0].ID);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f); glVertex3f(-WORLDSIZE, -5, -WORLDSIZE);
	glTexCoord2f(0.0f, 1); glVertex3f(-WORLDSIZE, -5, WORLDSIZE);
	glTexCoord2f(1, 1); glVertex3f(WORLDSIZE + 50, -5, WORLDSIZE);
	glTexCoord2f(1, 0.0f); glVertex3f(WORLDSIZE + 50, -5, -WORLDSIZE);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

