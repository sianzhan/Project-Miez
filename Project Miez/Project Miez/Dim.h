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

struct Face
{
	Point topLeft;
	Point btmRight;
	bool transparent;
	Face operator/(const float& f)
	{
		return Face(topLeft / f, btmRight / f, transparent);
	}
	Face() :topLeft(0, 0), btmRight(0, 0), transparent(0) {}
	Face(Point topLeft, Point btmRight, bool transparent) :topLeft(topLeft), btmRight(btmRight), transparent(transparent) {}
	Face(float topLeft_x, float topLeft_y, float btmRight_x, float btmRight_y, bool transparent) 
		:topLeft(topLeft_x, topLeft_y), btmRight(btmRight_x, btmRight_y), transparent(transparent) {}

};
