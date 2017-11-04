#pragma once
#include <GLUT/glut.h>
#include "../Dim.h"
struct Skin
{
	enum ID
	{
		HEAD,
		HELM,
		R_LEG,
		L_LEG,
		R_ARM,
		L_ARM,
		TORSO,
		R_LEG_L2,
		L_LEG_L2,
		R_ARM_L2,
		L_ARM_L2,
		TORSO_L2,
	};

	enum POS
	{
		TOP,
		BOTTOM,
		RIGHT,
		FRONT,
		LEFT,
		BACk
	};

	const static Face vexSkin[12][6];
	float skinSize;
	GLuint texId;

	Skin();
	Skin(GLuint, float);
	//Leturn the length of width / texSize
	float lenX(ID);
	float lenY(ID);
	float lenZ(ID);
};