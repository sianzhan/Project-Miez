#pragma once
#include "Display.h"
#include "Input.h"
#include "Craftian/Craftian.h"
class App : public Display, public Input
{
	Craftian *robot;
	int iSkin;
	std::vector<GLuint> dbTex;

	virtual void draw();
	virtual void timer();
	virtual void keyDown(int key);
public:
	App();
	void init();
	void start();
};