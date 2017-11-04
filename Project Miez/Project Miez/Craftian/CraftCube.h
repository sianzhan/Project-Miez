#pragma once
#include <vector>
#include <GLUT/glut.h>
#include "../Point.h"

struct Face
{
	Point topLeft;
	Point btmRight;
	bool transparent;
	Face():topLeft(0, 0), btmRight(0, 0), transparent(0) {}
	Face(Point topLeft, Point btmRight, bool transparent) :topLeft(topLeft), btmRight(btmRight), transparent(transparent) {}
};


//setTex must have been called first and tex size has to be set
class CraftCube
{
	Face faces[6] = {};
	GLuint texId = 0;
	float texSize = 0;
public:
	void setTop(Point topLeft, Point btmRight, bool transparent); // 0
	void setBtm(Point topLeft, Point btmRight, bool transparent); // 1
	void setRight(Point topLeft, Point btmRight, bool transparent); // 2
	void setFront(Point topLeft, Point btmRight, bool transparent); // 3
	void setLeft(Point topLeft, Point btmRight, bool transparent); // 4
	void setBack(Point topLeft, Point btmRight, bool transparent); // 5
	void setTop(float topLeft_x, float topLeft_y, float btmRight_x, float btmRight_y, bool transparent); // 0
	void setBtm(float topLeft_x, float topLeft_y, float btmRight_x, float btmRight_y, bool transparent); // 1
	void setRight(float topLeft_x, float topLeft_y, float btmRight_x, float btmRight_y, bool transparent); // 2
	void setFront(float topLeft_x, float topLeft_y, float btmRight_x, float btmRight_y, bool transparent); // 3
	void setLeft(float topLeft_x, float topLeft_y, float btmRight_x, float btmRight_y, bool transparent); // 4
	void setBack(float topLeft_x, float topLeft_y, float btmRight_x, float btmRight_y, bool transparent); // 5
	void setTex(GLuint, float);
	void draw();
};