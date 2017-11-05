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
		resetJoint();
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
		targets[TORSO$L_LEG].setAngle(Joint::X_AXIS, sin(tick / 3.0) * 80);
		targets[TORSO$R_LEG].setAngle(Joint::X_AXIS, cos(tick / 3.0) * 80);
		targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, sin(tick / 3.0) * 60);
		targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, cos(tick / 3.0) * 60);
		targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, sin(tick / 3.0) * (rand() % 40));
		targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, cos(tick / 3.0) * (rand() % 40));
		break;
	case BOW:
		targets[TORSO].setAngle(Joint::X_AXIS, 80);
		break;
	case SIT:
		targets[TORSO$L_LEG].setAngle(Joint::X_AXIS, -90);
		targets[TORSO$R_LEG].setAngle(Joint::X_AXIS, -90);
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