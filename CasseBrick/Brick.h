#pragma once
#include "GameObj.h"
class Brick : public GameObj
{
public:
	std::vector<float> GetAllPos();
	Brick(sf::RenderWindow* pWindow, int iWidth, int iHeight, int iPosX, int iPosY, sf::Color cColor);
	//sf::Vector2f GetBrick();
};


