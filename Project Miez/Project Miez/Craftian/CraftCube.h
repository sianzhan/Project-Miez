#pragma once
#include <vector>
#include <GLUT/glut.h>
#include "../Dim.h"
#include "Skin.h"

//setTex must have been called first and tex size has to be set
class CraftCube
{
	Face faces[6] = {};
	GLuint texId = 0;
	float texSize = 0;
public:
	CraftCube(GLuint texId, float texSize) :texId(texId), texSize(texSize) {}
	void setSkin(Skin);
	void setSkinPart(Skin::ID);
	void drawSkinPart(Skin::ID);
	void setTex(GLuint, float);

	void setTop(Face face) { faces[0] = face; }; // 0
	void setBtm(Face face) { faces[1] = face; }; // 1
	void setRight(Face face) { faces[2] = face; }; // 2
	void setFront(Face face) { faces[3] = face; };// 3
	void setLeft(Face face) { faces[4] = face; }; // 4
	void setBack(Face face) { faces[5] = face; }; // 5

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
	void draw();
};