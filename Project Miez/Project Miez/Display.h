//Display encapsulation

#pragma once
#include <string>
using namespace std;
class Display
{
private:
	static Display *target_display;
	const static std::string windowName;
	static int windowWidth;
	static int windowHeight;
	static void reshapeFunc(int, int);
	static void displayFunc();
	static void timerFunc(int);
protected:
	void init();
	virtual void timer() {};
	virtual void draw() {};
};
