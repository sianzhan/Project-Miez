#pragma once
#include "Joint.h"
class Skeleton
{
public:
	enum ANI
	{
		STILL,
		RUN,
		BOW,
		SIT,
		PLACE_HEAD,
		NONE,
		HELLO,
		DANCE,
		GANGNAM,
		SOMERSAULT,
		WAVEHAND_L,
		WAVEHAND_R,
		FLOWER
	};
protected:
	int i = 0;
	Joint joints[7];
	Joint targets[7];
	float height = 0;
	float targetHeight = 0;
	void resetJoint();
	unsigned long long tick = 0;
protected:
	ANI ani;
public:
	enum JOINT
	{
		TORSO,
		TORSO$HEAD,
		TORSO$R_ARM,
		TORSO$L_ARM,
		TORSO$R_LEG,
		TORSO$L_LEG,
		PIVOT
	};
	void actJoint(JOINT);
	void setJoint(JOINT joint, Joint::rotateAxis axis, float a, float x, float y, float z) 
	{
		targets[joint].setRotate(axis, a, x, y, z);
	}
	const Joint& getJoint(JOINT joint) { return joints[joint]; }
	void animate(ANI);
	void toggleAnimation(ANI);
	ANI getAnimation() { return ani; }
	void update();
	void setHeight(float h) { this->targetHeight = h; }
	const float& getHeight() const { return this->height; }
};