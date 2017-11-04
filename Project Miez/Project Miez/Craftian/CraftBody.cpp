#include "../Texture.h"
#include "CraftBody.h"
#include <cstdio>
GLuint CraftBody::skin_girl = -1;

struct Point 
{
	float x;
	float y;
};

CraftBody::CraftBody()
{
	printf("QQ");
}
const double texSize = 64.0;

void CraftBody::draw()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, skin_girl);
	glRotatef(60, 1, 1, 1);
	glScalef(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	Point texTopLeft, texBtmRight;
	double depthX, depthY, depthZ;
	//https://github.com/minotar/skin-spec

	//Precalculate Depth
	depthX = 8 / texSize;
	depthY = 12 / texSize;
	depthZ = 4 / texSize;

	//Torso Front - XY Plane - Pos Z
	texTopLeft.x = 20 / texSize, texTopLeft.y = (texSize - 20) / texSize;
	texBtmRight.x = 28 / texSize, texBtmRight.y = (texSize - 32) / texSize;
	glTexCoord2d(texTopLeft.x, texTopLeft.y); glVertex3d(-depthX, depthY, depthZ); //Top Left
	glTexCoord2d(texBtmRight.x, texTopLeft.y); glVertex3d(depthX, depthY, depthZ); //Top Right
	glTexCoord2d(texBtmRight.x, texBtmRight.y); glVertex3d(depthX, -depthY, depthZ); //Btm Right
	glTexCoord2d(texTopLeft.x, texBtmRight.y); glVertex3d(-depthX, -depthY, depthZ); //Btm Left

	//Torso Back - XY Plane - Neg Z
	texTopLeft.x = 32 / texSize, texTopLeft.y = (texSize - 20) / texSize;
	texBtmRight.x = 40 / texSize, texBtmRight.y = (texSize - 32) / texSize;
	glTexCoord2d(texTopLeft.x, texTopLeft.y); glVertex3d(-depthX, depthY, -depthZ); //Top Left
	glTexCoord2d(texBtmRight.x, texTopLeft.y); glVertex3d(depthX, depthY, -depthZ); //Top Right
	glTexCoord2d(texBtmRight.x, texBtmRight.y); glVertex3d(depthX, -depthY, -depthZ); //Btm Right
	glTexCoord2d(texTopLeft.x, texBtmRight.y); glVertex3d(-depthX, -depthY, -depthZ); //Btm Left

	//Torso Right - YZ Plane - Neg X
	texTopLeft.x = 16 / texSize, texTopLeft.y = (texSize - 20) / texSize;
	texBtmRight.x = 20 / texSize, texBtmRight.y = (texSize - 32) / texSize;
	glTexCoord2d(texTopLeft.x, texTopLeft.y); glVertex3d(depthX, depthY, depthZ); //Top Left
	glTexCoord2d(texBtmRight.x, texTopLeft.y); glVertex3d(depthX, depthY, -depthZ); //Top Right
	glTexCoord2d(texBtmRight.x, texBtmRight.y); glVertex3d(depthX, -depthY, -depthZ); //Btm Right
	glTexCoord2d(texTopLeft.x, texBtmRight.y); glVertex3d(depthX, -depthY, depthZ); //Btm Left

	//Torso Left - YZ Plane - Pos X
	texTopLeft.x = 28 / texSize, texTopLeft.y = (texSize - 20) / texSize;
	texBtmRight.x = 32 / texSize, texBtmRight.y = (texSize - 32) / texSize;
	glTexCoord2d(texTopLeft.x, texTopLeft.y); glVertex3d(-depthX, depthY, depthZ); //Top Left
	glTexCoord2d(texBtmRight.x, texTopLeft.y); glVertex3d(-depthX, depthY, -depthZ); //Top Right
	glTexCoord2d(texBtmRight.x, texBtmRight.y); glVertex3d(-depthX, -depthY, -depthZ); //Btm Right
	glTexCoord2d(texTopLeft.x, texBtmRight.y); glVertex3d(-depthX, -depthY, depthZ); //Btm Left

	//Torso Top - XZ Plane - Pos Y
	texTopLeft.x = 28 / texSize, texTopLeft.y = (texSize - 20) / texSize;
	texBtmRight.x = 32 / texSize, texBtmRight.y = (texSize - 32) / texSize;
	glTexCoord2d(texTopLeft.x, texTopLeft.y); glVertex3d(depthX, depthY, -depthZ); //Top Left
	glTexCoord2d(texBtmRight.x, texTopLeft.y); glVertex3d(depthX, depthY, depthZ); //Top Right
	glTexCoord2d(texBtmRight.x, texBtmRight.y); glVertex3d(-depthX, depthY, depthZ); //Btm Right
	glTexCoord2d(texTopLeft.x, texBtmRight.y); glVertex3d(-depthX, depthY, -depthZ); //Btm Left

	//Torso Btm - XZ Plane - Neg Y
	texTopLeft.x = 28 / texSize, texTopLeft.y = (texSize - 20) / texSize;
	texBtmRight.x = 32 / texSize, texBtmRight.y = (texSize - 32) / texSize;
	glTexCoord2d(texTopLeft.x, texTopLeft.y); glVertex3d(depthX, -depthY, -depthZ); //Top Left
	glTexCoord2d(texBtmRight.x, texTopLeft.y); glVertex3d(depthX, -depthY, depthZ); //Top Right
	glTexCoord2d(texBtmRight.x, texBtmRight.y); glVertex3d(-depthX, -depthY, depthZ); //Btm Right
	glTexCoord2d(texTopLeft.x, texBtmRight.y); glVertex3d(-depthX, -depthY, -depthZ); //Btm Left

	glEnd();
	glPopMatrix();
}

void CraftBody::init()
{
	skin_girl = Texture::GenTexture("res\\skin\\skin_girl.png");
}