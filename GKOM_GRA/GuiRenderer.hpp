#pragma once

class GuiRenderer {
public:
	static void RenderString(const int xpos, const int ypos, char * str);
	static void RenderBigRedString(const int xpos, const int ypos, char * str);
	static const int BOTTOM = 0;
	static const int MIDDLE = 1;
	static const int TOP = 2;
	static const int LEFT = 2;
	static const int RIGHT = 0;
private:
};