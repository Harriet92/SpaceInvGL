#pragma once

#include "texLoader.hpp"

const int width = 800;
const int height = 600;
const int WORLDSIZE = 100;
const int TEXTURES = 1;

class World {
public:
	World();
	void DrawEnvironment();
	bool initTexture();
private:
	TexLoader Textures[TEXTURES];
};
