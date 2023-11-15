#pragma once
#include "GameObj.h"
class Brick : public GameObj
{
private:
	int _iID;
	int _iHp;
public:
	Brick(sf::RenderWindow* pWindow, float iWidth, float iHeight, float iPosX, float iPosY, int iID);
	~Brick();
	void TakeDamage(int iDamage);

};


