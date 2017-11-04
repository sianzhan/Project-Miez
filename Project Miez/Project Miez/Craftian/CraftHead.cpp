#include "CraftHead.h"

CraftHead::CraftHead(GLuint skinId) :skinId(skinId)
{
	CraftCube::setTex(this->skinId, 64);

	//https://github.com/minotar/skin-spec
	CraftCube::setTop(8, 0, 16, 8, 0);
	CraftCube::setBtm(16, 0, 24, 8, 0);
	CraftCube::setRight(0, 8, 8, 16, 0);
	CraftCube::setFront(8, 8, 16, 16, 0);
	CraftCube::setLeft(16, 8, 24, 16, 0);
	CraftCube::setBack(24, 8, 32, 16, 0);
}

void CraftHead::draw()
{
	CraftCube::draw();
}
