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
	float pitch = 0;
	float yaw = 0;
	float roll = 0;
public:
	Craftian(GLuint texId, float size) :cube(texId, size), skin(texId,size) {}
	void setSkin(GLuint texId, float size);
	void draw();
	
	void move(int x, int y);
	void changeYaw(float yaw);
};