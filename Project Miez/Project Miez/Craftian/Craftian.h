//This is the robot class

#pragma once
#include <GLUT/glut.h>
#include "Skin.h"
class Craftian
{
	Skin skin;
public:
	Craftian() {};
	Craftian(GLuint, float);
	void draw();
};