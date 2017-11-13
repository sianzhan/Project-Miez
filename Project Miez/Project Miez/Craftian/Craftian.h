//This is the robot class
#define PI 3.14159
#pragma once
#include <vgl.h>
#include "Skin.h"
#include "Joint.h"
#include "Skeleton.h"
#include "CraftCube.h"
class Craftian : public Skeleton
{
	CraftCube cube;
	Skin skin;
	Point pos;
	float pitch = 0;
	float yaw = 0;
	float roll = 0;
	int headCount = 0;
	int targetHeadCount = 0;
	void test(int i);

public:
	Craftian(GLuint texId, float size) :cube(texId, size), skin(texId,size) {}
	void setSkin(GLuint texId, float size);
	void draw();
	void headStack() { targetHeadCount++; }
	void headPop() { targetHeadCount > 0 ? targetHeadCount-- : 0; }
	void move(int x, int y);
	void jump();
	void update();
	void changeYaw(float yaw);
	void changePitch(float pitch);
};