//This is the robot class
#define PI 3.14159
#pragma once
#include <vgl.h>
#include "Skin.h"
#include "Joint.h"
#include "Skeleton.h"
#include "CraftCube.h"
class Craftian
{
	CraftCube cube;
	Skin skin;
	Skeleton sku;
	Point pos;
	float lookAngle;
public:
	Craftian(GLuint texId, float size) :cube(texId, size), skin(texId,size), lookAngle(0) {}
	void setSkin(GLuint texId, float size);
	void draw();
	
	void move(float x, float y) 
	{ 
		pos.x += x, pos.y += y; 
	};
};