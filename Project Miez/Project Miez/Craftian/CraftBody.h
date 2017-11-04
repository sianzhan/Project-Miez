#pragma once
#include <GLUT/glut.h>
#include "CraftCube.h"
class CraftBody : private CraftCube
{
	GLuint skinId;
public:
	CraftBody() {};
	CraftBody(GLuint);
	void draw();
	void setSkinId(int);
};