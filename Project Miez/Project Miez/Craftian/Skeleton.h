#pragma once
#include "Joint.h"
class Skeleton
{
	Joint joints[5];
public:
	enum JOINT
	{
		TORSO$HEAD,
		TORSO$R_ARM,
		TORSO$L_ARM,
		TORSO$R_LEG,
		TORSO$L_LEG
	};
	void actJoint(JOINT);
};