#pragma once
#include "Joint.h"
class Skeleton
{
	Joint joints[6];
	Joint targets[6];
public:
	enum JOINT
	{
		TORSO,
		TORSO$HEAD,
		TORSO$R_ARM,
		TORSO$L_ARM,
		TORSO$R_LEG,
		TORSO$L_LEG
	};
	void actJoint(JOINT);

	enum ANI
	{
		STILL,
		RUN
	};
	void animate(ANI);
	void update();
};