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
	int id_effect = 0;
	int targetHeadCount = 0;
	bool hasSword = 1;
	void test(int i);
	void drawEffect();

public:
	Craftian(GLuint texId, float size) :cube(texId, size), skin(texId,size) {}
	void setSkin(GLuint texId, float size);
	void draw();
	void headStack() { targetHeadCount++; }
	void headPop() { targetHeadCount > 0 ? targetHeadCount-- : 0; }
	void move(int x, int y);
	void jump();
	void update();
	const Point& getPos() const {
		return this->pos;
	}
	void changeYaw(float yaw);
	void changePitch(float pitch);
	void effect(int e) { this->id_effect = e; };
	void toggleSword() { hasSword = (hasSword + 1) % 2; }
};