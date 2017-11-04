#pragma once
#include <GLUT/glut.h>
class CraftHand 
{
	GLuint skinId;
public:
	CraftHand() {};
	CraftHand(GLuint skinId):skinId(skinId) {};
	void draw();
};