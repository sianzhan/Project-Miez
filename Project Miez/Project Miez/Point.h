#pragma once
struct Point
{
	float x;
	float y;
	Point() :x(0), y(0) {}
	Point(float x, float y) : x(x), y(y) {}
	Point operator/(const float &f)
	{
		return Point(x / f, y / f);
	}
};