#pragma once
#include "GameObj.h"
class Brick : public GameObj
{
public:
	std::vector<int> GetAllPos();
	Brick(sf::RenderWindow* pWindow, int iWidth, int iHeight, int iPosX, int iPosY, sf::Color cColor);
	//sf::Vector2f GetBrick();
};


