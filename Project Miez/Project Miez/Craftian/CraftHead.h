#pragma once
#include "CraftCube.h"
class CraftHead : private CraftCube
{
	Skin skin;
public:
	CraftHead() {};
	CraftHead(Skin);
	void draw();
	void setSkin(Skin);
};