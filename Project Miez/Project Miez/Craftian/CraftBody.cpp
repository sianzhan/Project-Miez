#include "../Texture.h"
#include "CraftBody.h"
#include <cstdio>
GLuint CraftBody::skin_girl = -1;

CraftBody::CraftBody()
{
	printf("QQ");
}

void CraftBody::draw()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_RECTANGLE_ARB, skin_girl);
	glScalef(0.1, 0.2, 0.1);
	glBegin(GL_QUADS);
	glTexCoord2i(20, 32); glVertex2d(-1, -1);
	glTexCoord2i(28, 32); glVertex2d(1, -1);
	glTexCoord2d(28, 47); glVertex2d(1, 1);
	glTexCoord2d(20, 47); glVertex2d(-1, 1);
	glEnd();
	glPopMatrix();
}

void CraftBody::init()
{
	skin_girl = Texture::GenTexture("res\\skin\\skin_girl.png");
}