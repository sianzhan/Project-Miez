#include "Craftian.h"
#include "CraftCube.h"
#include <GLUT/glut.h>
Craftian::Craftian(GLuint texId, float size) :skin(texId, size){}

CraftCube cube;
float theta = 0;
void Craftian::draw()
{
	cube.setSkin(skin);
	glPushMatrix();
		glScalef(0.5, 0.5, 0.5);
		glRotatef(theta++, 0, 1, 0);

		glTranslatef(0, 0, 0);
		cube.drawSkinPart(Skin::TORSO);

		glPushMatrix();
			glTranslatef(0, skin.lenY(Skin::TORSO) + skin.lenY(Skin::HEAD), 0);
			cube.drawSkinPart(Skin::HEAD);

			glScalef(1.1, 1.1, 1.1);
			cube.drawSkinPart(Skin::HELM);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-(skin.lenX(Skin::TORSO) + skin.lenX(Skin::L_ARM)), 0, 0);
			cube.drawSkinPart(Skin::L_ARM);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(skin.lenX(Skin::TORSO) + skin.lenX(Skin::R_ARM), 0, 0);
			cube.drawSkinPart(Skin::R_ARM);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-skin.lenX(Skin::R_LEG), -(skin.lenY(Skin::TORSO) + skin.lenY(Skin::R_LEG)), 0);
			cube.drawSkinPart(Skin::R_LEG);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(skin.lenX(Skin::L_LEG), -(skin.lenY(Skin::TORSO) + skin.lenY(Skin::L_LEG)), 0);
			cube.drawSkinPart(Skin::L_LEG);
		glPopMatrix();

	glPopMatrix();
}