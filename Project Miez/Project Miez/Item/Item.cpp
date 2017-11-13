#include"Item.h"
void Item::draw() {
	sword= Texture::GenTexture("res\\skin\\sword.png");
	glBindTexture(GL_TEXTURE_2D, sword);
	//glRotatef(45.0, 0, 1, 0);
	glBegin(GL_QUADS);
	//double depthX, depthY, depthZ;
	glTexCoord2f(0,0); glVertex3f(0, 0,0); //Top Left
	glTexCoord2f(0,1); glVertex3f(0, 0.4, 0); //Top Right
	glTexCoord2f(1,1); glVertex3f(0.4, 0.4, 0); //Btm Right
	glTexCoord2f(1,0); glVertex3f(0.4, 0, 0); //Btm Left
	glEnd();
};