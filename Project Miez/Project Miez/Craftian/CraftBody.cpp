#include "../Texture.h"
#include "CraftBody.h"
#include <cstdio>
GLuint CraftBody::skin_girl = -1;

CraftBody::CraftBody()
{
	printf("QQ");
}
const float pix_ratio = 64.0;
void CraftBody::draw()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, skin_girl);
	glScalef(0.1, 0.2, 0.1);
	glBegin(GL_QUADS);
	glTexCoord2f(20/pix_ratio, 32/pix_ratio); glVertex2d(-1, -1);
	glTexCoord2f(28/pix_ratio, 32/pix_ratio); glVertex2d(1, -1);
	glTexCoord2f(28/pix_ratio, 47/pix_ratio); glVertex2d(1, 1);
	glTexCoord2f(20/pix_ratio, 47/pix_ratio); glVertex2d(-1, 1);
	glEnd();
	glPopMatrix();
}

void CraftBody::init()
{
	skin_girl = Texture::GenTexture("res\\skin\\skin_girl.png");
}