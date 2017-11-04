#include "Skin.h"
#include <GLUT/glut.h>

//https://github.com/minotar/skin-spec
const Face Skin::vexSkin[12][6]
=
{
	{Face(8, 0, 16, 8, 0), Face(16, 0, 24, 8, 0), Face(0, 8, 8, 16, 0), Face(8, 8, 16, 16, 0), Face(16, 8, 24, 16, 0), Face(24, 8, 32, 16, 0)}, //HEAD
	{Face(40, 0, 48, 8, 1), Face(48, 0, 56, 8, 1), Face(32, 8, 40, 16, 1), Face(40, 8, 48, 16, 1), Face(48, 8, 56, 16, 1), Face(56, 8, 64, 16, 1)}, //HELM
	{Face(4, 16, 8, 20, 0), Face(8, 16, 12, 20, 0), Face(0, 20, 4, 32, 0), Face(4, 20, 8, 32, 0), Face(8, 20, 12, 32, 0), Face(12, 20, 16, 32, 0)}, //R_LEG
	{Face(20, 48, 24, 52, 0), Face(24, 48, 28, 52, 0), Face(16, 52, 20, 64, 0), Face(20, 52, 24, 64, 0), Face(24, 52, 28, 64 ,0), Face(28, 52, 32, 64, 0)}, //L_LEG
	{Face(44, 16, 48, 20, 0), Face(48, 16, 52, 20 ,0), Face(40, 20, 44, 32, 0), Face(44, 20, 48, 32, 0), Face(48, 20, 52, 32, 0), Face(52, 20, 56, 32, 0)}, //R_ARM
	{Face(36, 48, 40, 52, 0), Face(40, 48, 44, 52, 0), Face(32, 52, 36, 64, 0), Face(36, 52, 40, 64, 0), Face(40, 52, 44, 64, 0), Face(44, 52, 48, 64, 0)}, //L_ARM
	{Face(20, 16, 28, 20, 0), Face(28, 16, 36, 20, 0), Face(16, 20, 20, 32, 0), Face(20, 20, 28, 32, 0), Face(28, 20, 32, 32, 0), Face(32, 20, 40, 32, 0)}, //TORSO
	{Face(4, 48, 8, 36, 1), Face(8, 48, 12, 36, 1), Face(0, 36, 4, 48, 1), Face(4, 36, 4, 48 ,1), Face(8, 36, 12, 48, 1), Face(12, 36, 16, 48, 1)}, //R_LEG_L2
	{Face(4, 48, 8, 52, 1), Face(8, 48, 12, 52, 1), Face(0, 52, 4, 64, 1), Face(4, 52, 8, 64, 1), Face(8, 52, 12, 64, 1), Face(12, 52, 16, 54, 1)}, //L_LEG_L2
	{Face(44, 48, 48, 36, 1), Face(48, 48, 52, 36, 1), Face(40, 36, 44, 48, 1), Face(44, 36, 48, 48, 1), Face(48, 36, 52, 48, 1), Face(52, 36, 64, 48, 1)}, //R_ARM_L2
	{Face(4, 48, 8, 52, 1), Face(8, 48, 12, 52, 1), Face(0, 52,4, 64, 1), Face(4, 52, 8, 64, 1), Face(8, 52, 12, 64, 1), Face( 12, 52, 16, 64, 1)}, //L_ARM_L2
	{Face(20, 48, 28, 36, 1), Face(28, 48, 36, 36, 1), Face(16, 36, 20, 48, 1), Face(20, 36, 28, 48, 1), Face(28, 36, 32, 48, 1), Face(32, 36, 40, 48, 1)} //TORSO_L2
};

Skin::Skin(){}

Skin::Skin(GLuint texId, float size): texId(texId), skinSize(size){}

float Skin::lenZ(Skin::ID id)
{
	return (vexSkin[id][Skin::RIGHT].btmRight.x - vexSkin[id][Skin::RIGHT].topLeft.x) / skinSize;
}
float Skin::lenY(Skin::ID id)
{
	return (vexSkin[id][Skin::FRONT].btmRight.y - vexSkin[id][Skin::FRONT].topLeft.y) / skinSize;
}
float Skin::lenX(Skin::ID id)
{
	return (vexSkin[id][Skin::FRONT].btmRight.x - vexSkin[id][Skin::FRONT].topLeft.x) / skinSize;
}