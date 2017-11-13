#pragma once
#include "Display.h"
#include "Input.h"
#include "Craftian/Craftian.h"

class App : public Display, public Input
{	
	Craftian *robot;
	int iSkin;
	std::vector<GLuint> dbTex;
	bool mouseLock = 0;
	bool day = 1; //day or night
	bool sai = 0;
	virtual void draw();
	virtual void timer();
	virtual void keyDown(int key);
	virtual void inputMouse(int button, int state, int x, int y);
	virtual void moveMouse(int x, int y);
public:
	App();
	void init();
	void start();
};