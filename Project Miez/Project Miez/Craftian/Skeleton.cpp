#include "Skeleton.h"
#define PI 3.14159
void Skeleton::actJoint(JOINT joint)
{
	joints[joint].act();
}

void Skeleton::animate(ANI ani)
{
	static float theta = 0;
	switch (ani)
	{
	case STILL:
		targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, 0);
		targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, 0);
		targets[TORSO$L_LEG].setAngle(Joint::X_AXIS, 0);
		targets[TORSO$R_LEG].setAngle(Joint::X_AXIS, 0);
		break;
	case RUN:
		theta += 0.5;
		targets[TORSO].setAngle(Joint::X_AXIS, rand()%10 - 5);
		targets[TORSO$L_LEG].setAngle(Joint::X_AXIS, sin(theta) * 80);
		targets[TORSO$R_LEG].setAngle(Joint::X_AXIS, cos(theta) * 80);
		targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, sin(theta) * 60);
		targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, cos(theta) * 60);
		targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, sin(theta) * (rand()%40));
		targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, cos(theta) * (rand()%40));
		break;

	default:;
	}
}

void Skeleton::update()
{
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