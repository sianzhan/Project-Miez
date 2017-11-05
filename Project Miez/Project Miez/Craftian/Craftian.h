//This is the robot class

#pragma once
#include <GLUT/glut.h>
#include "Skin.h"
#include "Joint.h"
#include "CraftCube.h"
class Craftian
{
	CraftCube cube;
	Skin skin;
public:
	Craftian(GLuint texId, float size) :cube(texId, size), skin(texId,size) {}
	void setSkin(GLuint texId, float size);
	void draw();
};