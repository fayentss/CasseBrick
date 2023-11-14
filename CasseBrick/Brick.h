#pragma once
#include "GameObj.h"
class Brick : public GameObj
{
public:
	Brick(sf::RenderWindow* pWindow, float iWidth, float iHeight, float iPosX, float iPosY, sf::Color cColor);
};


