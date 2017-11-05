#include "Joint.h"
#include <GLUT/glut.h>
#include <cstdio>

void Joint::act()
{
	for (int i = 0; i < 3; ++i)
	{
		glRotatef(rot[i].angle, rot[i].x, rot[i].y, rot[i].z);
	}
}