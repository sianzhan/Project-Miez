#include "Craftian.h"
#include <GLUT/glut.h>
Craftian::Craftian(GLuint skinId):skinId(skinId), body(skinId), head(skinId)
{}

float theta = 0;
void Craftian::draw()
{
	glPushMatrix();
		glScalef(0.5, 0.5, 0.5);
		glRotatef(theta, 0, 1, 0);
		glPushMatrix();
			glTranslatef(0, 0.29, 0);
			head.draw();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 0, 0);
			body.draw();
		glPopMatrix();

	glPopMatrix();
	theta += 1;
}