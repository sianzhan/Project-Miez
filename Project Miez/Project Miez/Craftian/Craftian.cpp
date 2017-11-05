#include "Craftian.h"
#define PI 3.14159
void Craftian::draw()
{
	glPushMatrix();
	    glTranslatef(pos.x/100, 0, pos.y/100);
		glRotatef(yaw, 0, 1, 0);
		glScalef(0.5, 0.5, 0.5);
		sku.actJoint(Skeleton::TORSO);
		cube.drawSkinPart(Skin::TORSO);

		glPushMatrix();
			glTranslatef(0, skin.lenY(Skin::TORSO), 0);
			//jointBegin(TORSO$HEAD);
			sku.actJoint(Skeleton::TORSO$HEAD);
			//jointEnd();
			glTranslatef(0, skin.lenY(Skin::HEAD), 0);
			cube.drawSkinPart(Skin::HEAD);

			glScalef(1.1, 1.1, 1.1);
			cube.drawSkinPart(Skin::HELM);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(skin.lenX(Skin::TORSO), skin.lenY(Skin::TORSO)*0.5, 0);
			//jointBegin(TORSO$R_ARM);
			sku.actJoint(Skeleton::TORSO$R_ARM);
			//jointEnd();
			glTranslatef(skin.lenX(Skin::R_ARM), -skin.lenY(Skin::TORSO)*0.6, 0);
			cube.drawSkinPart(Skin::R_ARM);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-skin.lenX(Skin::TORSO), skin.lenY(Skin::TORSO)*0.5, 0);
			//jointBegin(TORSO$L_ARM);
				sku.actJoint(Skeleton::TORSO$L_ARM);
			//jointEnd();
			glTranslatef(-skin.lenX(Skin::L_ARM), -skin.lenY(Skin::TORSO)*0.6, 0);
			cube.drawSkinPart(Skin::L_ARM);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(skin.lenX(Skin::R_LEG), -skin.lenY(Skin::TORSO), 0);
			//jointBegin(TORSO$R_LEG);
			sku.actJoint(Skeleton::TORSO$R_LEG);
			//jointEnd();
			glTranslatef(0, -skin.lenY(Skin::R_LEG), 0);
			cube.drawSkinPart(Skin::R_LEG);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-skin.lenX(Skin::L_LEG), -skin.lenY(Skin::TORSO), 0);
			//jointBegin(TORSO$L_LEG);
			sku.actJoint(Skeleton::TORSO$L_LEG);
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

void Craftian::move(int x, int y){
	if (x == 0 && y == 0)
	{
		sku.animate(Skeleton::STILL);
		sku.update();
	}
	else
	{
		pos.x += x * cos(yaw * PI / 180) + y * sin(yaw * PI / 180);
		pos.y += y * cos(yaw * PI / 180) - x * sin(yaw * PI / 180);
		sku.animate(Skeleton::RUN);
		sku.update();
	}
}

void Craftian::changeYaw(float yaw)
{
	this->yaw = fmod(this->yaw + yaw, 360);
};