#include "CraftHead.h"

CraftHead::CraftHead(Skin skin) :skin(skin)
{
	CraftCube::setSkin(skin);
	CraftCube::setSkinPart(Skin::TORSO);
}

void CraftHead::setSkin(Skin skin)
{
	this->skin = skin;
	CraftCube::setSkinPart(Skin::TORSO);
}

void CraftHead::draw()
{
	CraftCube::draw();
}