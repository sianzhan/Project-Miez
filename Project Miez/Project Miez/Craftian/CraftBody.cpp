#include "CraftBody.h"

void CraftBody::draw()
{
	glPushMatrix();
	glutSolidCube(0.2);
	glPopMatrix();
}