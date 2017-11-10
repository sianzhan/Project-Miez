#include "Skeleton.h"
#define PI 3.14159

void Skeleton::actJoint(JOINT joint)
{
	joints[joint].act();
}

void Skeleton::resetJoint()
{
	for (int i = 0; i < 6; ++i) targets[i] = Joint();
}

void Skeleton::toggleAnimation(ANI ani)
{
	if (getAnimation() == ani) animate(STILL);
	else animate(ani);
}

void Skeleton::animate(ANI ani)
{
	if (this->ani != ani)
	{
		this->ani = ani;
		tick = 0;
	}
}

void Skeleton::update()
{
	tick++;
	switch (ani)
	{
	case STILL:
		resetJoint();
		break;
	case RUN:
		targets[TORSO].setAngle(Joint::X_AXIS, rand() % 10 - 5);
		targets[TORSO$L_LEG].setAngle(Joint::X_AXIS, sin(tick / 4.0) * 80);
		targets[TORSO$R_LEG].setAngle(Joint::X_AXIS, cos(tick / 4.0+PI/2) * 80);
		targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, sin(tick / 4.0+PI/4) * 60);
		targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, cos(tick / 4.0+PI/3) * 60);
		targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, sin(tick / 4.0) * (rand() % 40));
		targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, cos(tick / 4.0) * (rand() % 40));
		break;
	case BOW:
		targets[TORSO].setAngle(Joint::X_AXIS, 80);
		break;
	case SIT:
		targets[TORSO$L_LEG].setAngle(Joint::X_AXIS, -90);
		targets[TORSO$R_LEG].setAngle(Joint::X_AXIS, -90);
		break;
	case PLACE_HEAD:
		if (tick < 5)
		{
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -40);
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -40);
		}
		else if (tick < 10)
		{
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -80);
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -80);
			targets[TORSO$L_ARM].setAngle(Joint::Y_AXIS, 20);
			targets[TORSO$R_ARM].setAngle(Joint::Y_AXIS, -20);
		}
		else if (tick < 20)
		{
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -120);
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -120);
		}
		else
		{
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, 0);
			animate(NONE);
		}
	case HELLO:
		if (tick < 10) {
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 20);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 150);
		}
		else if (tick < 20) {
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 110);
		}
		else if (tick < 30) {
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 20);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 150);
		}
		else if (tick < 40) {
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 110);
		}
		else {
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 0);
			animate(NONE);
		}

		
	default:;
	}


	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (joints[i].getAngle(j) != targets[i].getAngle(j))
				joints[i].setAngle(j, (joints[i].getAngle(j) + targets[i].getAngle(j))/2);
			if (joints[i].getX(j) != targets[i].getX(j))
				joints[i].setX(j, (joints[i].getX(j) + targets[i].getX(j))/2);
			if (joints[i].getY(j) != targets[i].getY(j))
				joints[i].setY(j, (joints[i].getY(j) + targets[i].getY(j))/2);
			if (joints[i].getZ(j) != targets[i].getZ(j))
				joints[i].setZ(j, (joints[i].getZ(j) + targets[i].getZ(j))/2);
		}
	}
}