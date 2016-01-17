#ifndef TEXTURE_H
#define TEXTURE_H

#include<stdio.h>
#include<windows.h>

const int BITMAP_ID = 0x4D42;

class TexLoader {
public:
	TexLoader();
	~TexLoader();
	bool load(char *name);
	void del();
	int getImageWidth() const { return imageWidth; }
	int getImageHeight() const { return imageHeight; }
	unsigned int ID;
	unsigned char *image;
private:
	int imageWidth;
	int imageHeight;
};

#endif
