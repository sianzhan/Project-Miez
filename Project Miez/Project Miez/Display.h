//Display encapsulation

#pragma once
#include <string>
using namespace std;
class Display
{
private:
	static Display *target_display;
	const static std::string windowName;
	static void reshapeFunc(int, int);
	static void displayFunc();
	static void timerFunc(int);
protected:
	static int windowWidth;
	static int windowHeight;
	void init();
	virtual void timer() {};
	virtual void draw() {};
};
