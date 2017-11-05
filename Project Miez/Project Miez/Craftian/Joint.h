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
	Joint() { std::fill_n(rot, 3, paramRotate()); };
	void act();
};