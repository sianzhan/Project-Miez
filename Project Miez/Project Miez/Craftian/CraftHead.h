#pragma once
#include <GLUT/glut.h>
#include "CraftCube.h"
class CraftHead : private CraftCube
{
	GLuint skinId;
public:
	CraftHead() {};
	CraftHead(GLuint skinId);
	void draw();
};