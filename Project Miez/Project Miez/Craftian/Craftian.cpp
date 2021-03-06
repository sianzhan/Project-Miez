#include "Craftian.h"
#include "../Item/Item.h"
#include <vector>
#define PI 3.14159

void Craftian::test(int i)
{
	static int step = 0;
	bool flag = 0;
	const static int maxStep = 3;
	if(i < headCount || i < targetHeadCount)
	{
		if (i == headCount - 1 && i >= targetHeadCount)
		{
			if (step == 0) step = maxStep;
			step--;
			glScalef(1.0*step / maxStep, 1.0*step / maxStep, 1.0*step / maxStep);
			if (step == 1) step = 0, headCount--;
		}
		else if (i >= headCount)
		{
			step++;
			glScalef(1.0*step / maxStep, 1.0*step / maxStep, 1.0*step / maxStep);
			if (step == maxStep) step = 0, headCount++;
		}

		else flag = 1;
		glPushMatrix(); //Set the joint of arm to 17/20 of torso
			glTranslatef(skin.lenX(Skin::HEAD), 0, 0);
			//jointBegin(TORSO$R_ARM);
			actJoint(TORSO$R_ARM);
			//jointEnd();
			glTranslatef(skin.lenX(Skin::R_ARM), -skin.lenY(Skin::HEAD)*0.8, 0);
			cube.drawSkinPart(Skin::R_ARM);
		glPopMatrix();

		glPushMatrix(); //Set the joint of arm to 17/20 of torso
			glTranslatef(-skin.lenX(Skin::HEAD), 0, 0);
			//jointBegin(TORSO$L_ARM);
			actJoint(TORSO$L_ARM);
			//jointEnd();
			glTranslatef(-skin.lenX(Skin::L_ARM), -skin.lenY(Skin::HEAD)*0.8, 0);
			cube.drawSkinPart(Skin::L_ARM);
		glPopMatrix();

		glRotatef(pitch, 1, 0, 0);
		glRotatef(roll, 0, 1, 0);
		glScalef(2.0, 2.0, 2.0);
		glPushMatrix();
			//jointBegin(TORSO$HEAD);
			actJoint(TORSO$HEAD);
			//jointEnd();
			glTranslatef(0, skin.lenY(Skin::HEAD), 0);
			cube.drawSkinPart(Skin::HEAD);
			glScalef(1.1, 1.1, 1.1);
			if(i == targetHeadCount-1) cube.drawSkinPart(Skin::HELM);
		glPopMatrix();
		glTranslatef(0, 2 * skin.lenY(Skin::HEAD), 0);
		if(flag) test(i + 1);
	}
}

void Craftian::drawEffect()
{
	static std::vector<paramRotate> balls;
	glPushMatrix();

	if (id_effect > 0)
	{
		while (balls.size() < id_effect) {
			balls.push_back(paramRotate(rand()%360, ((rand() % 134)-67) / 67.0, (rand() % 250 - 125) / 125.0, (rand() % 34 - 17) / 17.0));
		}
		for (int i = 0; i < id_effect; ++i)
		{
			glColor3f(id_effect *  (rand()%10) / 15.0, id_effect * ( rand()%10) / 15.0, id_effect * (rand()%10) / 15.0);
			balls[i].angle += (rand() % 17) / 17.0;
			glTranslatef(0, 0.3, 0);
			glRotatef(balls[i].angle, balls[i].x, balls[i].y, balls[i].z);
			
			glutSolidSphere(0.005, 10, 10);
		}
	}
	glPopMatrix();
}

void Craftian::draw()
{
	glPushMatrix();
	    glTranslatef(pos.x/100, 0, pos.y/100);
		drawEffect();
		glTranslatef(0, height, 0);
		glRotatef(yaw, 0, 1, 0); //Set Yaw
		actJoint(PIVOT);
		glScalef(0.45, 0.45, 0.45); 
		float rise = fmax(fabs(cos(getJoint(TORSO$R_LEG).getAngle(Joint::X_AXIS) * PI / 180))
			, fabs(cos(getJoint(TORSO$L_LEG).getAngle(Joint::X_AXIS) * PI / 180)));
		//height according to leg height
		if (getAnimation() == RUN) rise = rise * 0.05 + 0.95;
		glTranslatef(0, 2*skin.lenY(Skin::L_LEG)*rise, 0); //Set the joint of torso to bottom

		glPushMatrix();
			glTranslatef(skin.lenX(Skin::R_LEG), 0, 0); //Set the joint of leg to top
			//jointBegin(TORSO$R_LEG);
			actJoint(TORSO$R_LEG);
			//jointEnd();
			glTranslatef(0, -skin.lenY(Skin::R_LEG), 0); 
			cube.drawSkinPart(Skin::R_LEG);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-skin.lenX(Skin::L_LEG), 0, 0); //Set the joint of leg to top
			//jointBegin(TORSO$L_LEG);
			actJoint(TORSO$L_LEG);
			//jointEnd();
			glTranslatef(0, -skin.lenY(Skin::L_LEG), 0);
			cube.drawSkinPart(Skin::L_LEG);
		glPopMatrix();

		//jointBegin(TORSO);
		actJoint(TORSO);
		//jointEnd(TORSO);
		glTranslatef(0, skin.lenY(Skin::TORSO), 0);
		cube.drawSkinPart(Skin::TORSO);
		glPushMatrix();
			glPushMatrix(); //Set the joint of arm to 17/20 of torso
				glTranslatef(-skin.lenX(Skin::TORSO), skin.lenY(Skin::TORSO)*0.7, 0);
				//jointBegin(TORSO$R_ARM);
				actJoint(TORSO$R_ARM);
				//jointEnd();
				glTranslatef(-skin.lenX(Skin::R_ARM), -skin.lenY(Skin::TORSO)*0.8, 0);
			
				cube.drawSkinPart(Skin::R_ARM);
			glPopMatrix();

			glPushMatrix(); //Set the joint of arm to 17/20 of torso
				glTranslatef(skin.lenX(Skin::TORSO), skin.lenY(Skin::TORSO)*0.7, 0);
				//jointBegin(TORSO$L_ARM);
				actJoint(TORSO$L_ARM);
				//jointEnd();
				glTranslatef(skin.lenX(Skin::L_ARM), -skin.lenY(Skin::TORSO)*0.8, 0);
				cube.drawSkinPart(Skin::L_ARM);
			glPopMatrix();
			glTranslatef(0, skin.lenY(Skin::TORSO), 0); //Set the joint to torso top

			glRotatef(pitch, 1, 0, 0);
			glRotatef(roll, 0, 1, 0);
			glScalef(1.5, 1.5, 1.5);
			glPushMatrix();
				//jointBegin(TORSO$HEAD);
				actJoint(TORSO$HEAD);
				//jointEnd();
				glTranslatef(0, skin.lenY(Skin::HEAD), 0);
				cube.drawSkinPart(Skin::HEAD);
				glScalef(1.1, 1.1, 1.1);
				if(targetHeadCount == 0)cube.drawSkinPart(Skin::HELM);
			glPopMatrix();
			glTranslatef(0, 2*skin.lenY(Skin::HEAD), 0);

			test(0);

		glPopMatrix();

		//FOr drawing equipments on hand
		glPushMatrix();
			//Left Hand
			glPushMatrix(); //Set the joint of arm to 17/20 of torso
				glTranslatef(-skin.lenX(Skin::TORSO), skin.lenY(Skin::TORSO)*0.7, 0);
				//jointBegin(TORSO$R_ARM);
				actJoint(TORSO$R_ARM);
				//jointEnd();
				glTranslatef(-skin.lenX(Skin::R_ARM), -skin.lenY(Skin::TORSO)*0.8, 0);
				if (hasSword)
				{
					Item item;
					glTranslatef(0, -0.1, -0.05);
					glRotatef(-90, 0, 1, 0);
					glRotatef(-45, 0, 0, 1);
					item.draw();
				}
			glPopMatrix();

			//Right Hand
			glPushMatrix(); //Set the joint of arm to 17/20 of torso
			glPopMatrix();
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
		if(ani == RUN) animate(STILL);
	}
	else
	{
		pos.x += x * cos(yaw * PI / 180) + y * sin(yaw * PI / 180);
		pos.y += y * cos(yaw * PI / 180) - x * sin(yaw * PI / 180);

		this->yaw += this->roll * 0.03;
		this->roll -= this->roll * 0.03;

		animate(RUN);
	}
}

void Craftian::update()
{
	if (targetHeight > 0) targetHeight -= 0.02;
	if (height<targetHeight) height += targetHeight / 15;
	else if (targetHeight < 0) targetHeight = 0, height = 0;
	else height = targetHeight;
	Skeleton::update();
}

void Craftian::jump()
{
	if(height < 0.1) targetHeight = 0.5;
}

void Craftian::changeYaw(float yaw)
{
	const static int maxRoll = 60;
	this->roll += yaw;
	if(this->roll > maxRoll) this->yaw = fmod(this->yaw + this->roll - maxRoll, 360), this->roll = maxRoll;
	if (this->roll < -maxRoll) this->yaw = fmod(this->yaw + this->roll + maxRoll, 360), this->roll = -maxRoll;
};

void Craftian::changePitch(float pitch)
{
	pitch /= -3;
	const static int maxPitch = 60;
	this->pitch = this->pitch + pitch;
	if (this->pitch > maxPitch) this->pitch = maxPitch;
	else if (this->pitch < -maxPitch) this->pitch = -maxPitch;
};

