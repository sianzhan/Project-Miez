#include "CraftCube.h"
#include <stdexcept>
#include <iterator>
void CraftCube::draw()
{
	if (texSize <= 0) throw std::runtime_error("Please set the texture size first");
	glBindTexture(GL_TEXTURE_2D, texId);
	glBegin(GL_QUADS);
	double depthX, depthY, depthZ;

	//Precalculate Depth
	depthX = (faces[3].btmRight.x - faces[3].topLeft.x);
	depthY = (faces[3].topLeft.y - faces[3].btmRight.y);
	depthZ = (faces[4].btmRight.x - faces[4].topLeft.x);

	//Top - XZ Plane - Pos Y
	glNormal3f(0, 1, 0);
	glTexCoord2d(faces[0].topLeft.x, faces[0].topLeft.y); glVertex3d(depthX, depthY, -depthZ); //Top Left
	glTexCoord2d(faces[0].btmRight.x, faces[0].topLeft.y); glVertex3d(depthX, depthY, depthZ); //Top Right
	glTexCoord2d(faces[0].btmRight.x, faces[0].btmRight.y); glVertex3d(-depthX, depthY, depthZ); //Btm Right
	glTexCoord2d(faces[0].topLeft.x, faces[0].btmRight.y); glVertex3d(-depthX, depthY, -depthZ); //Btm Left

	//Btm - XZ Plane - Neg Y
	glNormal3f(0, 1, 1);
	glTexCoord2d(faces[1].topLeft.x, faces[1].topLeft.y); glVertex3d(depthX, -depthY, -depthZ); //Top Left
	glTexCoord2d(faces[1].btmRight.x, faces[1].topLeft.y); glVertex3d(depthX, -depthY, depthZ); //Top Right
	glTexCoord2d(faces[1].btmRight.x, faces[1].btmRight.y); glVertex3d(-depthX, -depthY, depthZ); //Btm Right
	glTexCoord2d(faces[1].topLeft.x, faces[1].btmRight.y); glVertex3d(-depthX, -depthY, -depthZ); //Btm Left
																					  
	//Right - YZ Plane - Neg X
	glTexCoord2d(faces[2].topLeft.x, faces[2].topLeft.y); glVertex3d(depthX, depthY, depthZ); //Top Left
	glTexCoord2d(faces[2].btmRight.x, faces[2].topLeft.y); glVertex3d(depthX, depthY, -depthZ); //Top Right
	glTexCoord2d(faces[2].btmRight.x, faces[2].btmRight.y); glVertex3d(depthX, -depthY, -depthZ); //Btm Right
	glTexCoord2d(faces[2].topLeft.x, faces[2].btmRight.y); glVertex3d(depthX, -depthY, depthZ); //Btm Left

	//Front - XY Plane - Pos Z
	glTexCoord2d(faces[3].topLeft.x, faces[3].topLeft.y); glVertex3d(-depthX, depthY, depthZ); //Top Left
	glTexCoord2d(faces[3].btmRight.x, faces[3].topLeft.y); glVertex3d(depthX, depthY, depthZ); //Top Right
	glTexCoord2d(faces[3].btmRight.x, faces[3].btmRight.y); glVertex3d(depthX, -depthY, depthZ); //Btm Right
	glTexCoord2d(faces[3].topLeft.x, faces[3].btmRight.y); glVertex3d(-depthX, -depthY, depthZ); //Btm Left

	//Left - YZ Plane - Pos X
	glTexCoord2d(faces[4].topLeft.x, faces[4].topLeft.y); glVertex3d(-depthX, depthY, depthZ); //Top Left
	glTexCoord2d(faces[4].btmRight.x, faces[4].topLeft.y); glVertex3d(-depthX, depthY, -depthZ); //Top Right
	glTexCoord2d(faces[4].btmRight.x, faces[4].btmRight.y); glVertex3d(-depthX, -depthY, -depthZ); //Btm Right
	glTexCoord2d(faces[4].topLeft.x, faces[4].btmRight.y); glVertex3d(-depthX, -depthY, depthZ); //Btm Left

	//Back - XY Plane - Neg Z
	glTexCoord2d(faces[5].topLeft.x, faces[5].topLeft.y); glVertex3d(-depthX, depthY, -depthZ); //Top Left
	glTexCoord2d(faces[5].btmRight.x, faces[5].topLeft.y); glVertex3d(depthX, depthY, -depthZ); //Top Right
	glTexCoord2d(faces[5].btmRight.x, faces[5].btmRight.y); glVertex3d(depthX, -depthY, -depthZ); //Btm Right
	glTexCoord2d(faces[5].topLeft.x, faces[5].btmRight.y); glVertex3d(-depthX, -depthY, -depthZ); //Btm Left

	glEnd();
}

void CraftCube::setSkin(Skin skin)
{
	this->setTex(skin.texId, skin.skinSize);
}

void CraftCube::setSkinPart(Skin::ID id)
{
	for (int i = 0; i < 6; ++i)
	{
		faces[i] = Skin::vexSkin[id][i];
		faces[i].btmRight.y = texSize - faces[i].btmRight.y;
		faces[i].topLeft.y = texSize - faces[i].topLeft.y;
		faces[i] = faces[i] / texSize;
	}
}

void CraftCube::drawSkinPart(Skin::ID id)
{
	setSkinPart(id);
	draw();
}

void CraftCube::setTop(Point topLeft, Point btmRight, bool transparent)
{
	if (texSize <= 0) throw std::runtime_error("Please set the texture size first");
	topLeft.y = texSize - topLeft.y, btmRight.y = texSize - btmRight.y;
	faces[0] = Face(topLeft / texSize, btmRight / texSize, transparent);
}
void CraftCube::setBtm(Point topLeft, Point btmRight, bool transparent)
{
	if (texSize <= 0) throw std::runtime_error("Please set the texture size first");
	topLeft.y = texSize - topLeft.y, btmRight.y = texSize - btmRight.y;
	faces[1] = Face(topLeft / texSize, btmRight / texSize, transparent);
}
void CraftCube::setRight(Point topLeft, Point btmRight, bool transparent)
{
	if (texSize <= 0) throw std::runtime_error("Please set the texture size first");
	topLeft.y = texSize - topLeft.y, btmRight.y = texSize - btmRight.y;
	faces[2] = Face(topLeft / texSize, btmRight / texSize, transparent);
}
void CraftCube::setFront(Point topLeft, Point btmRight, bool transparent)
{
	if (texSize <= 0) throw std::runtime_error("Please set the texture size first");
	topLeft.y = texSize - topLeft.y, btmRight.y = texSize - btmRight.y;
	faces[3] = Face(topLeft / texSize, btmRight / texSize, transparent);
}
void CraftCube::setLeft(Point topLeft, Point btmRight, bool transparent)
{
	if (texSize <= 0) throw std::runtime_error("Please set the texture size first");
	topLeft.y = texSize - topLeft.y, btmRight.y = texSize - btmRight.y;
	faces[4] = Face(topLeft / texSize, btmRight / texSize, transparent);
}
void CraftCube::setBack(Point topLeft, Point btmRight, bool transparent)
{
	if (texSize <= 0) throw std::runtime_error("Please set the texture size first");
	topLeft.y = texSize - topLeft.y, btmRight.y = texSize - btmRight.y;
	faces[5] = Face(topLeft / texSize, btmRight / texSize, transparent);
}

void CraftCube::setTop(float topLeft_x, float topLeft_y, float btmRight_x, float btmRight_y, bool transparent)
{
	this->setTop(Point(topLeft_x, topLeft_y), Point(btmRight_x, btmRight_y), transparent);
}// 0
void CraftCube::setBtm(float topLeft_x, float topLeft_y, float btmRight_x, float btmRight_y, bool transparent)
{
	this->setBtm(Point(topLeft_x, topLeft_y), Point(btmRight_x, btmRight_y), transparent);
}// 1
void CraftCube::setRight(float topLeft_x, float topLeft_y, float btmRight_x, float btmRight_y, bool transparent)
{
	this->setRight(Point(topLeft_x, topLeft_y), Point(btmRight_x, btmRight_y), transparent);
}// 2
void CraftCube::setFront(float topLeft_x, float topLeft_y, float btmRight_x, float btmRight_y, bool transparent)
{
	this->setFront(Point(topLeft_x, topLeft_y), Point(btmRight_x, btmRight_y), transparent);
}// 3
void CraftCube::setLeft(float topLeft_x, float topLeft_y, float btmRight_x, float btmRight_y, bool transparent)
{
	this->setLeft(Point(topLeft_x, topLeft_y), Point(btmRight_x, btmRight_y), transparent);
}// 4
void CraftCube::setBack(float topLeft_x, float topLeft_y, float btmRight_x, float btmRight_y, bool transparent)
{
	this->setBack(Point(topLeft_x, topLeft_y), Point(btmRight_x, btmRight_y), transparent);
}// 5

void CraftCube::setTex(GLuint texId, float texSize)
{
	this->texId = texId;
	this->texSize = texSize;
}