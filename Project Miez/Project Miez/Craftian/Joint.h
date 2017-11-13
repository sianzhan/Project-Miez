#pragma once
#include <algorithm>
struct paramRotate
{
	float angle;
	float x;
	float y;
	float z;
	paramRotate() :angle(0), x(0), y(0), z(0) {}
	paramRotate(float a, float x, float y, float z) : angle(a), x(x), y(y), z(z) {}
};

class Joint
{
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
	void setRotate(int i, float a, float x, float y, float z) { 
		rot[i].angle = a, rot[i].x = x, rot[i].y = y, rot[i].z = z; 
	}

	void setAngle(int a, float f) { rot[a].angle = f; }
	void setX(int a, float f) { rot[a].x = f; }
	void setY(int a, float f) { rot[a].y = f; }
	void setZ(int a, float f) { rot[a].z = f; }
	const float& getAngle(int a) const{ return rot[a].angle; }
	const float& getX(int a) const{ return rot[a].x; }
	const float& getY(int a) const{ return rot[a].y; }
	const float& getZ(int a) const{ return rot[a].z; }
};