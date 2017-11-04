#pragma once
#include "CraftCube.h"
class CraftBody : private CraftCube
{
	Skin skin;
public:
	CraftBody() {};
	CraftBody(Skin);
	void draw();
	void setSkin(Skin);
};