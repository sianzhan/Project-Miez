#include "Craftian.h"

float theta = 0;
void Craftian::draw()
{
	glPushMatrix();
		glScalef(0.5, 0.5, 0.5);
		glRotatef(theta++, 0, 1, 0);

		glTranslatef(0, 0, 0);
		cube.drawSkinPart(Skin::TORSO);

		glPushMatrix();
			glTranslatef(0, skin.lenY(Skin::TORSO), 0);
			//jointBegin(TORSO^HEAD);
			glRotatef(10, 1, 0, 0);
			//jointEnd();
			glTranslatef(0, skin.lenY(Skin::HEAD), 0);
			cube.drawSkinPart(Skin::HEAD);

			glScalef(1.1, 1.1, 1.1);
			cube.drawSkinPart(Skin::HELM);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(skin.lenX(Skin::TORSO), skin.lenY(Skin::TORSO)*0.5, 0);
			//jointBegin(TORSO^R_ARM);
			glRotatef(30, 0, 1, 0);
			glRotatef(30, 0, 0, 1);
			//jointEnd();
			glTranslatef(skin.lenX(Skin::R_ARM), -skin.lenY(Skin::TORSO)*0.6, 0);
			cube.drawSkinPart(Skin::R_ARM);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-skin.lenX(Skin::TORSO), skin.lenY(Skin::TORSO)*0.5, 0);
			//jointBegin(TORSO^L_ARM);
			glRotatef(-30, 0, 1, 0);
			glRotatef(-30, 0, 0, 1);
			//jointEnd();
			glTranslatef(-skin.lenX(Skin::L_ARM), -skin.lenY(Skin::TORSO)*0.6, 0);
			cube.drawSkinPart(Skin::L_ARM);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-skin.lenX(Skin::R_LEG), -skin.lenY(Skin::TORSO), 0);
			//jointBegin(TORSO^R_LEG);
			glRotatef(-10, 1, 0, 0);
			//jointEnd();
			glTranslatef(0, -skin.lenY(Skin::R_LEG), 0);
			cube.drawSkinPart(Skin::R_LEG);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(skin.lenX(Skin::L_LEG), -skin.lenY(Skin::TORSO), 0);
			//jointBegin(TORSO^L_LEG);
			glRotatef(10, 1, 0, 0);
			//jointEnd();
			glTranslatef(0, -skin.lenY(Skin::L_LEG), 0);
			cube.drawSkinPart(Skin::L_LEG);
		glPopMatrix();

	glPopMatrix();

}

void Craftian::setSkin(GLuint texId, float size)
{
	skin = Skin(texId, size);
	cube.setSkin(skin);
}