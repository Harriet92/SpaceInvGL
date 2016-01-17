#pragma once

class Input {
public:
	static void ProcessNormalKeys(unsigned char key, int x, int y);
	static void ReleaseNormalKey(unsigned char key, int x, int y);
	static void PressKey(int key, int x, int y);
	static void ReleaseKey(int key, int x, int y);
	static void MouseMove(int mX, int mY);
	static void MouseEnter(int state);
	static void MouseClick(int button, int state, int x, int y);
	static float GetMove() { return move; }
	static float GetStrife() { return strife; }
	static bool shoot;
private:
	static int move;
	static float strife;
	static float angleUp;
	static float mouseX;
	static float mouseY;
	static bool left_down;
};