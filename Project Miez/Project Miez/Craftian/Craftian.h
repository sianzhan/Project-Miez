//This is the robot class

#pragma once
#include "CraftBody.h"
#include "CraftHead.h"
class Craftian
{
	CraftBody body;
	CraftHead head;
	GLuint skinId;

public:
	Craftian() {};
	Craftian(GLuint);
	void draw();
};