#include "CraftBody.h"
#include <cstdio>

CraftBody::CraftBody(GLuint skinId):skinId(skinId)
{
	CraftCube::setTex(this->skinId, 64);

	//https://github.com/minotar/skin-spec
	CraftCube::setTop(20, 16, 28, 20 , 0);
	CraftCube::setBtm(28, 16, 36, 20, 0);
	CraftCube::setRight(16, 20, 20, 32, 0);
	CraftCube::setFront(20, 20, 28, 32, 0);
	CraftCube::setLeft(28, 20, 32, 32, 0);
	CraftCube::setBack(32, 20, 40, 32, 0);
}

void CraftBody::setSkinId(int skinId)
{
	this->skinId = skinId;
	CraftCube::setTex(this->skinId, 64);
}

void CraftBody::draw()
{
	CraftCube::draw();
}
