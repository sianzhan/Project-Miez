#pragma once
#include <algorithm>
class Joint
{
	struct paramRotate
	{
		float angle;
		float x;
		float y;
		float z;
		paramRotate() :angle(0), x(0), y(0), z(0) {}
	};

	paramRotate rot[3];
public:
	Joint() { 
		std::fill_n(rot, 3, paramRotate()); 
		rot[X_AXIS].x = 1, rot[Y_AXIS].y = 1, rot[Z_AXIS].z = 1; 
	}
	void act();

	enum rotateAxis
	{
		X_AXIS = 0,
		Y_AXIS = 1,
		Z_AXIS = 2
	};
	void setAngle(int a, float f) { rot[a].angle = f; }
	void setX(int a, float f) { rot[a].x = f; }
	void setY(int a, float f) { rot[a].y = f; }
	void setZ(int a, float f) { rot[a].z = f; }

	float getAngle(int a) { return rot[a].angle; }
	float getX(int a) { return rot[a].x; }
	float getY(int a) { return rot[a].y; }
	float getZ(int a) { return rot[a].z; }
};