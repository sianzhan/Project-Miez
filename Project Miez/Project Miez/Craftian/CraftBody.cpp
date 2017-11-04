#include "CraftBody.h"
#include "Skin.h"
#include <cstdio>

CraftBody::CraftBody(Skin skin):skin(skin)
{
	CraftCube::setSkin(skin);
	CraftCube::setSkinPart(Skin::TORSO);
}

void CraftBody::setSkin(Skin skin)
{
	this->skin = skin;
	CraftCube::setSkinPart(Skin::TORSO);
}

void CraftBody::draw()
{
	CraftCube::draw();
}
